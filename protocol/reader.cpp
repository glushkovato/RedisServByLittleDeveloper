#include "reader.h"

char Reader::read_char() {
    if (rpos_ == end_) read_more();
    return buffer_[rpos_++];
}

int64_t Reader::read_int() {
    int64_t i = 0;
    int counter = 0;
    bool negative = false;

    char first = read_char(), next;
    if (first == '-') {
        negative = true;
        next = read_char();
    } else {
        next = first;
    }

    do {
        i *= 10;
        //i += next - '0';
        if (__builtin_saddl_overflow(i, next - '0', &i)) {
            throw std::invalid_argument("integer overflow");
        }
        next = read_char();
        ++counter;
    } while((next != '\r') && (counter < 20));

    if (counter > 19) {
        throw std::invalid_argument("bad value of integer");
    }

    read_char(); // skip '\n'

    return negative ? -i : i;
}

std::string Reader::read_string() {
    char checker;
    int counter = 0;
    std::string string_out;
    while((checker = read_char()) != '\r') {
        string_out.push_back(checker);
        ++counter;
    }
    if (counter > 1024*1024) {  // проверка длины строки(ограничение - 1 мб)
        throw std::exception("");
    }
    read_char();
    return string_out;
}

std::vector<char> Reader::read_raw(size_t len) {
    std::vector<char> string_out;
    string_out.resize(len);
    for(int i = 0; i != len; ++i) {
        string_out[i] = read_char();
    }
    read_char();
    read_char();
    return string_out;
}

void StringReader::read_more() {
    if (input.empty()) throw std::runtime_error("end of input");

    end_ = 0;
    rpos_ = 0;
    for (; end_ < input.size() && end_ < buffer_.size(); ++end_) {
        buffer_[end_] = input[end_];
    }

    input.erase(input.begin(), input.begin() + end_);
}
