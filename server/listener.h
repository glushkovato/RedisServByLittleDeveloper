//
// Created by glushkovato on 11.11.15.
//

#pragma once

#include <bits/unique_ptr.h>
#include "sys/socket.h"
#include <unistd.h>
#include "socket.h"
#include<arpa/inet.h> //inet_addr

class Listener {
private:
    void socket_();
    void bind_();
    void listen_();
    void setsockopt_();
    int socket_desc;
    int port;
    int connect_counter;
public:

    // создаёт объекты типа Socket
    Listener(int port);
    std::unique_ptr<Socket> accept();

};

// Даём классу Listener порт и получаем соединение