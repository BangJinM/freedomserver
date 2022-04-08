#pragma once

#include "src/loginserver/LoginServer.hpp"

namespace fs
{
    class FreedomServer
    {

    private:
        FreedomServer();
        ~FreedomServer();

    public:
        static FreedomServer *GetInstance();

        void Init(int argc, char *const argv[]);
        void Start(int argc, char *const argv[]);

    private:
        void runFreedomServer();
        void runLogServer(int server_id);
        void runDBServer(int server_id);
        void runLoginServer(int server_id);
        void runGateServer(int server_id);
        void runGameServer(int server_id);

        ls::LoginServer loginServer;
    private:
        static FreedomServer *gFreedomServer;
    };
};