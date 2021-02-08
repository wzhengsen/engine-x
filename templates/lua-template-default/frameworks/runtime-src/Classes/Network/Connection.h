#pragma once
#include "mongoose/mongoose.h"
#include <string>
#include <map>
#include <functional>
namespace StarryX {
	namespace Network {
		/*
		基于mongoose的类封装
		*/
		class Connection {
        private:
            struct MgrWrapper;
		public:
			struct MessageBuffer;
			/*
				消息结构
				所有的收发消息都应遵循此结构。
                每一个连接都具有一个对应的MessageBuffer来缓存收到的数据，最大长度Message::MaxMsgLen，无效的长度将导致连接关闭
                每一组有效数据必定需要由uint32_t的头部指示数据区长度，由拆包导致无法完全解析的数据将暂存于MessageBuffer
			*/
			struct Message final {
				//最大消息长度，超过此长度可能导致连接被主动关闭
				static constexpr uint32_t MaxMsgLen = uint16_t(~0) + 1;

                inline Message() = default;

                inline Message(uint32_t len) noexcept {
                    this->len = len;
                    buff = ::malloc(len);
                }

                inline ~Message() {
                    if (buff) {
                        ::free(buff);
                        buff = nullptr;
                    }
                }

                inline void Resize(size_t len) noexcept {
                    this->len = len;
                    buff = ::realloc(buff, len);
                }

                inline Message(Message&& m) noexcept {
                    std::swap(len, m.len);
                    std::swap(buff, m.buff);
                }

                inline Message(const Message& m) noexcept {
                    len = m.len;
                    if (len) {
                        buff = ::malloc(len);
                        ::memcpy(buff, m.buff, len);
                    }
                }

                inline Message& operator=(const Message& m) noexcept {
                    if (buff) {
                        ::free(buff);
                    }
                    len = m.len;
                    if (len) {
                        buff = ::malloc(len);
                        ::memcpy(buff, m.buff, len);
                    }
                    return *this;
                }

                inline uint32_t GetLen() const noexcept {
                    return static_cast<uint32_t>(len);
                }

                inline void* GetBuff() const noexcept {
                    return buff;
                }

            private:
                //消息长度
                size_t len = 0;
                //真实消息首部指针
                void* buff = nullptr;
			};

			/*
				用于消息缓冲，最大缓冲为Message::MaxMsgLen
			*/
			struct MessageBuffer final {
			public:
				MessageBuffer(size_t initSize = InitMsgLen) noexcept;
				~MessageBuffer();

                /*
                    Desc:   清除缓冲区长度（并未清空缓冲区）
                */
                inline void Clear() noexcept {
                    size = 0;
                }

                /*
                    Desc:	从buff中解析消息，若消息合法，将其加入缓冲区。
                    Param:	buff:	消息数据首地址。
                            len:	消息数据长度。
                    Return:	是否合法解析。
                */
                bool ParseData(const void* buff, size_t len);

                /*
                    Desc:   从头部清除指定长度的缓冲区，并将后方剩余的缓冲区前移。
                    Param:  len     清除缓冲区的长度。
                */
                void Cut(size_t len) noexcept;

                /*
                    Desc:	从缓冲区中读取消息，若消息结构合法（4字节指示长度的头部+足够长的数据区），
                            则将返回指定的内存区，内存区大小通过ReadLen()获取。
                    Param:  len         读取数据长度。
                    Return: 数据区的指针.
                */
                const void* GetData(size_t& len) const noexcept;

                static constexpr uint32_t InitMsgLen = 512;
			private:
				size_t capacity = InitMsgLen;
				size_t size = 0;
				void* buffer = nullptr;
                static constexpr uint32_t MaxMsgLen = Message::MaxMsgLen;

                /*
                    Desc:   将一段内存数据追加到内部缓冲区末尾。
                    Param:	src         内存数据区指针。
                            len         数据长度。
                    Return: 缓冲区容量超限MaxMsgLen导致返回false,否则返回true
                */
                bool Append(const void* src, size_t len);

                /*
                    Desc:	获取下一个有效消息的长度，不包括消息头部的4个字节。
                    Return:	有效数据区长度。
                            返回0表示消息不合法或未达到可读取的长度。
                */
                uint32_t GetLen() const noexcept;
			};

			/*
				连接事件
			*/
			enum Event {
				MG_Poll = MG_EV_POLL,			/* Sent to each connection on each mg_mgr_poll() call */
				MG_Accept = MG_EV_ACCEPT,		/* New connection accepted. union socket_address * */
				MG_Connect = MG_EV_CONNECT,	/* connect() succeeded or failed. int *  */
				MG_Recv = MG_EV_RECV,			/* Data has been received. int *num_bytes */
				MG_Close = MG_EV_CLOSE,		/* Connection is closed. NULL */
				MG_Timer = MG_EV_TIMER,		/* now >= conn->ev_timer_time. double * */

				MG_None = 9999
			};

			enum Type {
				TCP,//默认
				UDP
			};

			/*
				用于回调传参
			*/
			struct Info final {
				/*
					MG_Poll/MG_Timer将内部处理，不会在回调中监听到
					MG_Accept/MG_Connect/MG_Recv/MG_Send/MG_Close可以在回调中监听到
				*/
				Event event = MG_None;

				const mg_connection* conn = nullptr;

                /*
                    MG_Recv事件时，该字段才起作用
                */
                Message* msg = nullptr;

                /*
                    MG_Connect失败时，该字段为false
                */
                bool suc = false;

                /*
                    MG_Accpet事件时，赋值为地址和端口。
                */
                std::string addr = std::string();
                uint16_t port = 0;

                inline Info() noexcept {
                    msg = new Message();
                }

                inline ~Info() {
                    if (msg) {
                        delete msg;
                    }
                }
			};

			/*
				回调函数原型
			*/
            typedef std::function<void(const Connection* conn, const Info* eventInfo)> EventHandler;

			virtual ~Connection();
			Connection(const Connection&) = delete;
			Connection& operator=(const Connection&) = delete;

			virtual void Close() const;

			/*
				为每个连接设置独立的事件响应
			*/
            void SetHandler(EventHandler eh) noexcept {
                eventHandler = eh;
            }
            inline EventHandler GetHandler() const noexcept {
                return eventHandler;
            }
            inline Type GetType() const noexcept {
                return ct;
            }
            inline const mg_connection* GetConnection() const noexcept { return mgCon; };

            /*
                直接销毁 mg_mgr，此操作会同时销毁所有的连接和socket
            */
            static void CloseMGR() noexcept;
            static void Poll() noexcept;
		protected:
			Connection(Type ct = TCP) noexcept;

            void InitConnection(const std::string& addr, uint16_t port);
			std::string connAddr = "";
			mg_connection* mgCon = nullptr;
			EventHandler eventHandler = nullptr;

			Type ct = Type::TCP;
            static mg_mgr* mgMgr;
			static std::map<const mg_connection*, MessageBuffer> mgBuffMap;

			/*
				mongoose回调
			*/
			static void MG_EventHandler(mg_connection* nc, int ev, void* ev_data);
		private:
			std::string addr = "";
            uint16_t port = 0;

			static constexpr char UDP_Header[] = "udp://";
			static constexpr char TCP_Header[] = "tcp://";

            static size_t activeCount;
		};
	};
};