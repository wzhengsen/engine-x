#pragma once
#include "Connection.h"
#include <vector>
namespace StarryX {
	namespace Network {
		class Server : public Connection {
		public:
			enum class State {
				Closed,
				Listening
			};

			Server(Type ct = TCP) noexcept;
			~Server();

			/*
				返回true代表mg_connection是否创建和状态检验通过
			*/
			bool Bind(const std::string& addr, uint16_t port);
			bool Bind(uint16_t port);

			/*
				Func:	TCP连接发送消息，且会在消息头部附加uint32_t，表示长度
				Param:	mgCon	发送消息的连接，若不填该参数，将向所有连接的端发送。
				Desc:	mgCon表示的连接一定要是该Server所连接的，否则不能成功发送
			*/
			void Send(mg_connection* mgCon, const void* buff, size_t len) const;
			void Send(mg_connection* mgCon, const char* buff) const;
			void Send(mg_connection* mgCon, const std::string& str) const;
			void Send(mg_connection* mgCon, const Message& msg) const;
            inline void Send(const void* buff, size_t len) const {
                for (auto it = conVec.cbegin(); it != conVec.cend(); it++) {
                    Send(*it, buff, len);
                }
            };
            void Send(const char* buff) const {
                for (auto it = conVec.cbegin(); it != conVec.cend(); it++) {
                    Send(*it, buff);
                }
            };
            void Send(const std::string& str) const {
                for (auto it = conVec.cbegin(); it != conVec.cend(); it++) {
                    Send(*it, str);
                }
            };
            void Send(const Message& msg) const {
                for (auto it = conVec.cbegin(); it != conVec.cend(); it++) {
                    Send(*it, msg);
                }
            };

			/*
				关闭Server
			*/
			void Close() const override;
			/*
				关闭Server的某一个连接，mgCon表示的连接一定要是该Server所连接的
			*/
			void Close(mg_connection* mgCon) const;

			/*
				返回当前连接状态。
			*/
			State GetState() const noexcept { return cs; };

			/*
				返回全部对等连接。
			*/
			const std::vector<mg_connection*>& GetSockets() const noexcept { return conVec; };
		private:
			std::vector<mg_connection*> conVec = std::vector<mg_connection*>();
			State cs = State::Closed;
			static void MG_EventHandler(mg_connection* nc, int ev, void* ev_data);
		};
	};
};