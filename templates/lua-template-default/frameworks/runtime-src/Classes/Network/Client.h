#pragma once
#include "Connection.h"
namespace StarryX {
	namespace Network {

		class Client : public Connection {
			/*
				简单的客户端实现
			*/
		public:
			enum class State {
				Closed,
				Connecting,
				Connected
			};

			Client(Type ct = TCP) noexcept;

			/*
				返回true仅代表mg_connection是否创建和状态检验通过，不表示成功连接
			*/
			bool Connect(const std::string& addr, uint16_t port, bool broadcast = false, uint32_t timeout = ConnectTimeout);

			/*
				TCP连接会在消息头部附加uint32_t，表示长度
			*/
			void Send(const void* buff, size_t len) const noexcept;
			void Send(const char* buff) const noexcept;
			void Send(const std::string& str) const noexcept;
			void Send(const Message& msg) const noexcept;

			/*
				返回当前连接状态。
			*/
			State GetState() const noexcept { return cs; };
		private:
			State cs = State::Closed;
			static void MG_EventHandler(mg_connection* nc, int ev, void* ev_data);
			/*
				连接事件超时毫秒数，超过该时间，自动断开连接
			*/
			static constexpr uint32_t ConnectTimeout = 5000;
		};
	};
};