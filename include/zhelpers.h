/**
 * @file zhelpers.h
 * @author Paran Lee (p4ranlee@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright ZeroMQ Cookbook Authors 2022
 * 
 */

#include <zmq.h>
#include <string.h>
#include <assert.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(s) Sleep(s)
#elif __linux__
#include <unistd.h>
#else
#   error "Unknown compiler"
#endif

static int s_send(void *socket, char *string)
{
    int rc;
    zmq_msg_t message;

    zmq_msg_init_size(&message, strlen(string));
    memcpy(zmq_msg_data(&message), string, strlen(string));
    
    rc = zmq_msg_send(&message, socket, 0);
    assert(!rc);

    zmq_msg_close(&message);

    return (rc);
}

// Receive 0MQ string from socket and convert into C string
static char * s_recv(void *socket)
{
    zmq_msg_t message;

    zmq_msg_init(&message);
    zmq_msg_recv(&message, socket, 0);

    int size = zmq_msg_size(&message);

    char *string = (char *) malloc(size + 1);
    memcpy(string, zmq_msg_data(&message), size);
    string [size] = 0;

    zmq_msg_close(&message);

    return string;
}
