//
// Created by glushkovato on 11.11.15.
//
#pragma once

class Socket {
public:
    int filedes;
    Socket(int new_filedes);  // конструктор
    ~Socket();  // деструктор

    std::string* get(size_t max_size_of_buf);
    void send(std::string* res_of_get);
};

