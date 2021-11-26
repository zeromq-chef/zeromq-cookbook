/* ZeroMQ Cookbook
Copyright (C) 2021 The ZeroMQ Cookbook Authors.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
==============================================================================*/

#include <iostream>
#include <string>

#include <zmq.hpp>

int main(int argc, char* argv[]) {
    zmq::context_t context;
    zmq::socket_t socket(context, zmq::socket_type::rep);
    // SO_REUSEADDR is not supported in ZeroMQ, so try ZMQ_SNDBUF instead
    // socket.set(zmq::socket_option::send_buffer_size, 4096);
    socket.bind("tcp://127.0.0.1:20000");
    std::cout << "Echo server running on port 20000\n" << std::endl;

    while (true) {
        zmq::message_t request;
        socket.recv(request);

        std::cout << "Received: \n" << request << std::endl;

        socket.send(request);
    }

    return 0;
}
