#include "../networking/networking.h"
#include "../multiplexers/events.h"

void worker(char *address, int port)
{
    int listend = create_listener(address, port);

    if (listend < 0)
        return;

    int evloopd = create_loop();
    register_socket(evloopd, listend);
}