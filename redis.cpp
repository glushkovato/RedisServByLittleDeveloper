#include "redis.h"

void WriteRedisValue(Writer* w, const RedisValue& value) {
    if (value.which() == REDIS_INT) {
        w->write_char(':');
        w->write_int(boost::get<int64_t>(value));
        w->write_crlf();
    } else if (value.which() == REDIS_STRING) {
        w->write_char('+');
        w->write_string(boost::get<std::string>(value));
        w->write_crlf();
    } else if (value.which() == REDIS_BULK_STRING) {
        w->write_char('$');
        auto vct = boost::get<std::vector<char>>(value);
        w->write_raw(std::string(vct.begin(), vct.end()).c_str(), vct.size());
        w->write_crlf();
    } else if (value.which() == REDIS_ERROR) {
        w->write_char('-');
        w->write_string(boost::get<RedisError>(value).msg);
        w->write_crlf();
    } else if (value.which() == REDIS_ARRAY) {
        w->write_char('*');
        auto arr_vct = boost::get<std::vector<RedisValue>>(value);
        for (size_t i = 0; i != arr_vct.size(); ++i) {
            WriteRedisValue(w, arr_vct[i]);
        }
    } else if (value.which() == REDIS_NULL) {
        w->write_char('$');
        w->write_int(-1);
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
            int64_t n = r->read_int();
            for (int i = 0; i != n; ++i) {
                ReadRedisValue( r, value);
            }
            break;
        }
        case '$': {
            int64_t len = r->read_int();
            if (len < 0) {
                *value = RedisNull();
            } else {
                *value = r->read_raw(len); // bulk string
            }
            break;
        }
        case '+': {
            *value = r->read_line();
            break;
        }
        case '-': {
            *value = r->read_line();
            break;
        }
        default:
            throw std::runtime_error("invalid redis value");
    }
}


