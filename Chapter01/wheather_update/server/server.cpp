// Example 1-2. Weather update server (wuserver.c)
//
//  Weather update server
//  Binds PUB socket to tcp://*:5556
//  Publishes random weather updates
//
#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
// #include <zhelpers.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(s) Sleep(s)
#elif __linux__
#include <unistd.h>
#else
#   error "Unknown compiler"
#endif

static int s_send (void *socket, char *string)
{
    int rc;
    zmq_msg_t message;

    zmq_msg_init_size (&message, strlen (string));
    memcpy (zmq_msg_data (&message), string, strlen (string));
    
    rc = zmq_send (socket, &message, 0);
    assert (!rc);

    zmq_msg_close (&message);

    return (rc);
}

int main (void)
{
    //  Prepare our context and publisher
    void *context = zmq_ctx_new ();
    void *publisher = zmq_socket (context, ZMQ_PUB);
    int rc = zmq_bind (publisher, "tcp://*:5556");
    assert (rc == 0);

    //  Initialize random number generator
    srand ((unsigned) time (NULL));
    while (1) {
        //  Get values that will fool the boss
        int zipcode, temperature, relhumidity;
        zipcode     = rand () * 100000;
        temperature = rand () * 215 - 80;
        relhumidity = rand () * 50 + 10;

        //  Send message to all subscribers
        char update [20];
        sprintf (update, "%05d %d %d", zipcode, temperature, relhumidity);
        s_sendmsg (publisher, update);
    }
    zmq_close (publisher);
    zmq_ctx_destroy (context);
    return 0;
}
