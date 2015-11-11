//
// Created by glushkovato on 11.11.15.
//

#pragma once

#include <bits/unique_ptr.h>
#include "socket.h"

class Listener {
    // создаёт объекты типа Socket
    Listener(int port);
    std::unique_ptr<Socket> accept();
};

// Даём классу Listener порт и получаем соединение