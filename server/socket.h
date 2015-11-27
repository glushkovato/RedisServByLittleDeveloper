//
// Created by glushkovato on 11.11.15.
//

#ifndef HSE_SAMPLE_PROJECT_SOCKET_H
#define HSE_SAMPLE_PROJECT_SOCKET_H

class Socket {
private:
    int filedes;

public:
    Socket(int new_filedes);  // конструктор
    ~Socket();  // деструктор

    std::string* get(size_t max_size_of_buf);
    void send(std::string* res_of_get);
};

#endif //HSE_SAMPLE_PROJECT_SOCKET_H
