#include <iostream>
#include "server/server.h"
#include "protocol/redis.h"


int main() {
    Server ser = Server(6379);
    ser.foo();
    return 0;
}
