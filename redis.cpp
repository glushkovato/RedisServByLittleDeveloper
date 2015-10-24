#include "redis.h"

void WriteRedisValue(Writer* w, const RedisValue& value) {
    if (value.which() == REDIS_INT) {
        w->write_char(':');
        w->write_int(boost::get<int64_t>(value));
        w->write_crlf();
    } else {
        throw std::runtime_error("unsupported type");
    }
}

void ReadRedisValue(Reader* r, RedisValue* value) {
    switch(r->read_char()) {
        case ':': {
            *value = r->read_int();
            break;
        }
        case '*': {
            break;
        }
        case '$': {
            ssize_t len = r->read_int();
            if (len < 0) {
                *value = RedisNull();
            } else {
                *value = r->read_raw(len);
            }
            break;
        }
        case '+': {
            *value = r->read_line();
            break;
        }
        case '-': {
            *value = r->read_error();
            break;
        }
        default:
            throw std::runtime_error("invalid redis value");
    }
}


