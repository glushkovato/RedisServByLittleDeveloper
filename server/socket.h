//
// Created by glushkovato on 11.11.15.
//
#pragma once

class Socket {
public:
    int filedes;
    Socket(int new_filedes);  // конструктор
    ~Socket();  // деструктор

    int get(char *input_data, size_t max_size_of_buf);
    int send(char *output_data, size_t size_of_output_data);
};

