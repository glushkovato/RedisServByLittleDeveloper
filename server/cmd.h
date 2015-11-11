//
// Created by glushkovato on 11.11.15.
//

#ifndef HSE_SAMPLE_PROJECT_CMD_H
#define HSE_SAMPLE_PROJECT_CMD_H

#include <bits/stringfwd.h>
#include <protocol/redis.h>

class Cmd {
    virtual ~Cmd() {}
    virtual std::string name() = 0;  // находим имя команды
    virtual RedisValue exec(RedisValue args) = 0;
};

#endif //HSE_SAMPLE_PROJECT_CMD_H
