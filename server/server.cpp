//
// Created by glushkovato on 11.11.15.
//

#include <protocol/reader.h>
#include <protocol/writer.h>
#include <protocol/redis.h>
#include "server.h"

Server::Server(int port) : opener(port) {}

void Server::foo() {  // функция, с помощью которой сервер начинает обрабатывать соединения
    std::unique_ptr<Socket> res = opener.accept_conn();
//    while(1) {
//
//       //std::unique_ptr<Socket> res = opener.accept_conn();
//   }

    SocketReader info_from_client(res->filedes);
    SocketWriter info_to_client(res->filedes);

    while(1) {  // парсим строку от клиента и записываем в val
        RedisValue val;
        ReadRedisValue(&info_from_client, &val);
        //std::unique_ptr<Socket> res = opener.accept_conn();
    }
}

