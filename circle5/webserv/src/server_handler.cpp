#include "../inc/webserv.hpp"

int start_server(WebservConfig cfg)
{
    Server s;

    try {
        s.init(cfg);
    } catch(const std::exception& e)
    {
        s.log(e.what(), RED);
        s.log("Error: Failed to init server", RED);
        return (ERR_RET);
    }

    s.run();
    return (SUCCESS);
}
