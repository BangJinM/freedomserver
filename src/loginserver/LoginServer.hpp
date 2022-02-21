#pragma once

#include "hv/Channel.h"
#include "hv/TcpServer.h"
#include "hv/Buffer.h"
#include "../base/Message.hpp"

namespace ls
{
    class LoginServer : public hv::TcpServer
    {
    public:
        LoginServer() : TcpServer()
        {
            onConnection = [](const hv::SocketChannelPtr &channel)
            {
                std::string peeraddr = channel->peeraddr();
                if (channel->isConnected())
                {
                    printf("%s connected! connfd=%d\n", peeraddr.c_str(), channel->fd());
                }
                else
                {
                    printf("%s disconnected! connfd=%d\n", peeraddr.c_str(), channel->fd());
                }
            };
            onMessage = HandleMessage;
            // init protorpc_unpack_setting
            unpack_setting_t protorpc_unpack_setting;
            memset(&protorpc_unpack_setting, 0, sizeof(unpack_setting_t));
            protorpc_unpack_setting.mode = UNPACK_BY_LENGTH_FIELD;
            protorpc_unpack_setting.package_max_length = DEFAULT_PACKAGE_MAX_LENGTH;
            protorpc_unpack_setting.body_offset = 4;
            protorpc_unpack_setting.length_field_offset = 0;
            protorpc_unpack_setting.length_field_bytes = 4;
            protorpc_unpack_setting.length_field_coding = ENCODE_BY_BIG_ENDIAN;
            setUnpack(&protorpc_unpack_setting);
        }

        int Listen(int port) { return createsocket(port); }

    private:
        static void HandleMessage(const hv::SocketChannelPtr &channel, hv::Buffer *buf)
        {
            // unpack -> Request::ParseFromArray -> router -> Response::SerializeToArray -> pack -> Channel::write
            // protorpc_unpack
            printf(buf->base);
            Message message;
            message.Decode(buf);
            printf(message.ToString().c_str());
        }
    };

}