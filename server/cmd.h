//
// Created by glushkovato on 11.11.15.
//
#pragma once
#include <bits/stringfwd.h>
#include <protocol/redis.h>

class Cmd {
    virtual ~Cmd() {}
    virtual std::string name() = 0;  // находим имя команды
    virtual RedisValue exec(RedisValue args) = 0;
};

//class Get : public Cmd {
//
//};
//
//class Set : public Cmd {
//
//};

