#include "lanucher/FreedomServer.hpp"

#include "loginserver/LoginServer.hpp"

using namespace hv;

int main(int argc, char *argv[])
{
    hlog_set_level(LOG_LEVEL_DEBUG);
    
    fs::FreedomServer *server = fs::FreedomServer::GetInstance();
    server->Init(argc, argv);
    server->Start(argc, argv);

    while (1)
        hv_sleep(1);

    return 0;
}
