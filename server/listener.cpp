//
// Created by glushkovato on 11.11.15.
//

#include <netinet/in.h>
#include "listener.h"

void Listener::socket_() {
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        throw std::invalid_argument("Could not create socket");
        // printf("Could not create socket");
    }
}

void Listener::bind_() {
    struct sockaddr_in server;
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        throw std::runtime_error("Bind failed");
        //puts("bind failed");
    }
}

void Listener::listen_() {
    listen(socket_desc , connect_counter);
}

void Listener::setsockopt_() {
    int opt = 1;
    setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
}

std::unique_ptr<Socket> Listener::accept() {
    struct sockaddr_in tmp;
    socklen_t slen = sizeof(tmp);

    std::unique_ptr<Socket> newClient(new Socket(accept(socket_desc, (struct sockaddr *) &tmp, &slen)));
    return newClient;
}