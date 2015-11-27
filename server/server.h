//
// Created by glushkovato on 11.11.15.
//
#pragma once
#include "listener.h"

class Server {
private:
    Listener opener;
public:
    Server(int port);  // Server(int port, int connect_counter);
    void foo();
};
