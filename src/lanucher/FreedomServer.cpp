#include "FreedomServer.hpp"

#include "src/loginserver/LoginServer.hpp"

#include <string>
#include <vector>
#include <sstream>
namespace fs
{
    FreedomServer *FreedomServer::gFreedomServer = nullptr;

    FreedomServer::FreedomServer()
    {
    }
    FreedomServer::~FreedomServer()
    {
    }

    FreedomServer *FreedomServer::GetInstance()
    {
        if (!gFreedomServer)
            gFreedomServer = new FreedomServer();
        return gFreedomServer;
    }

    void FreedomServer::Init(int argc, char *const argv[])
    {
    }
    void FreedomServer::Start(int argc, char *const argv[])
    {
        runFreedomServer();
    }

    void FreedomServer::runFreedomServer()
    {
        ls::LoginServer server;
        int listenfd = server.Listen(4444);
        if (listenfd)
        {
            server.setThreadNum(4);
            server.start();
        }
    }
    void FreedomServer::runLogServer(int server_id)
    {
    }
    void FreedomServer::runDBServer(int server_id)
    {
    }
    void FreedomServer::runLoginServer(int server_id)
    {
    }
    void FreedomServer::runGateServer(int server_id)
    {
    }

    void FreedomServer::runGameServer(int server_id)
    {
    }
};