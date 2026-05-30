#include "chatserver.hpp"
#include "json.hpp"
#include "chatservice.hpp"

#include <functional>
#include <string>
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

// 初始化聊天服务器对象
ChatServer::ChatServer(EventLoop* loop, const InetAddress& listenAddr,const string& nameArg)
    : server_(loop, listenAddr, nameArg),
      loop_(loop)
{
    // 注册链接回调
    server_.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));
    // 注册读写事件回调
    server_.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));
    // 设置合适的线程数量
    server_.setThreadNum(4);
}

// 启动聊天服务器
void ChatServer::start()
{
    server_.start();
}


// 上报链接相关信息的回调函数
void ChatServer::onConnection(const TcpConnectionPtr& conn)
{
    if (!conn->connected())
    {
        ChatService::instance()->clientCloseException(conn);
        conn->shutdown();
    }

}

// 上报读写事件相关信息的回调函数
void ChatServer::onMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp receiveTime)
{
    string buf = buffer->retrieveAllAsString();
    // 数据的反序列化
    json js = json::parse(buf);
    // 达到的目的：完全解耦网络模块和业务模块的代码
    // 通过js["msgid"] 获取msgid，然后分发给不同的业务处理
    auto msgHandler = ChatService::instance()->getHandler(js["msgid"].get<int>());
    // 回调消息对应的处理方法，执行业务操作
    msgHandler(conn, js, receiveTime);
}