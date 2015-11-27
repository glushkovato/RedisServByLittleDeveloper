#include "writer.h"

void Writer::write_int(int64_t i) {
    char buff[128];
    int len = snprintf(buff, sizeof(buff), "%ld", i);

    write_raw(buff, len);
}

void Writer::write_raw(const char* s, size_t len) {
    for(int i = 0; i < len; ) {
        while(i < len && wpos_ != buffer_.size()) {
            buffer_[wpos_++] = s[i++];
        }

        if (wpos_ == buffer_.size())
            flush();
    }
}

void Writer::write_char(char c) {
    buffer_[wpos_++] = c;

    if (wpos_ == buffer_.size())
        flush();
}

void Writer::write_string(const std::string& s) {
    write_raw(s.c_str(), s.size());
}

void Writer::write_crlf() {
    write_char('\r');
    write_char('\n');
}

void StringWriter::flush() {
    result.append(buffer_.begin(), buffer_.begin() + wpos_);
    wpos_ = 0;
}

void SocketWriter::flush() {
    std::string * out = new std::string(buffer_.begin(), buffer_.begin() + wpos_);
    socket_.send(out);
    wpos_ = 0;
}
