//
// Created by glushkovato on 11.11.15.
//

#include <stdexcept>
#include <unistd.h>
#include "socket.h"

Socket::Socket(int new_filedes) {
    if (new_filedes > 0) {
        filedes = new_filedes;
    } else {
        throw std::invalid_argument("wrong value of filedes");
    }
}

Socket::~Socket() {
    close(filedes);
}

std::string* Socket::get(size_t max_size_of_buf) {
    std::string *res_of_get = new std::string();
    res_of_get->resize(max_size_of_buf);
    max_size_of_buf = read(filedes, (char*)(res_of_get->c_str()), max_size_of_buf);
    res_of_get->resize(max_size_of_buf);
    return res_of_get;
}

void Socket::send(std::string* res_of_get) {
    for(int size_of_res = 0; size_of_res < res_of_get->size(); size_of_res += write(filedes, res_of_get, res_of_get->size() - size_of_res)) {
    }
}

