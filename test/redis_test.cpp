#include "redis.h"
#include <boost/algorithm/string/join.hpp>
#include <gtest/gtest.h>

TEST(RedisValue, Construct) {
    RedisValue integer = 10;
    RedisValue string = "abcd";
    RedisValue error = RedisError("Permission denied");
    RedisValue array = std::vector<RedisValue>{integer, string, error};
    RedisValue bulk_str = std::vector<char>();
}

TEST(WriteRedisValue, Int) {
    RedisValue i = 10, j = -5;

    StringWriter writer(1024);
    WriteRedisValue(&writer, i);
    writer.flush();

    EXPECT_STREQ(":10\r\n", writer.result.c_str());

    writer.result.clear();
    WriteRedisValue(&writer, j);
    writer.flush();

    EXPECT_STREQ(":-5\r\n", writer.result.c_str());
}

TEST(ReadRedisValue, Int) {
    RedisValue val;

    StringReader reader;

    reader.input = ":10\r\n";
    ReadRedisValue(&reader, &val);
    EXPECT_EQ(10, boost::get<int64_t>(val));

    reader.input = ":-5\r\n";
    ReadRedisValue(&reader, &val);
    EXPECT_EQ(-5, boost::get<int64_t>(val));
}

TEST(WriteRedisValue, string) {
    RedisValue s = "lol";

    StringWriter writer(1024);
    WriteRedisValue(&writer, s);
    writer.flush();

    EXPECT_STREQ("+lol\r\n", writer.result.c_str());
}

TEST(ReadRedisValue, string) {
    RedisValue val;

    StringReader reader;
    reader.input = "+lol\r\n";
    ReadRedisValue(&reader, &val);

    EXPECT_STREQ("lol", boost::get<std::string>(val).c_str());
}

TEST(WriteRedisValue, redisError) {
    RedisValue val = RedisError("ERROR");

    StringWriter writer(1024);
    WriteRedisValue(&writer, val);
    writer.flush();

    EXPECT_STREQ("-ERROR\r\n", writer.result.c_str());
}

TEST(ReadRedisValue, redisError) {
    RedisValue val;

    StringReader reader;
    reader.input = "-ERROR\r\n";
    ReadRedisValue(&reader, &val);

    EXPECT_STREQ("ERROR", boost::get<RedisError>(val).msg.c_str());
}

TEST(WriteRedisValue, Array) {
    RedisValue integer = 10;
    RedisValue string = "lol";
    RedisValue error = RedisError("Permission denied");
    RedisValue array1 = std::vector<RedisValue>{integer, string, error};
    RedisValue array2 = std::vector<RedisValue>{};

    std::string tmp_bulk = "abcd";
    RedisValue bulk_str = std::vector<char>(tmp_bulk.begin(), tmp_bulk.end());
    RedisValue array3 = std::vector<RedisValue>{bulk_str};

    StringWriter writer(1024);
    WriteRedisValue(&writer, array1);
    writer.flush();

    EXPECT_STREQ("*3\r\n:10\r\n+lol\r\n-Permission denied\r\n", writer.result.c_str());

    writer.result.clear();
    WriteRedisValue(&writer, array2);
    writer.flush();

    EXPECT_STREQ("*0\r\n", writer.result.c_str());

    writer.result.clear();
    WriteRedisValue(&writer, array3);
    writer.flush();

    EXPECT_STREQ("*1\r\n$4\r\nabcd\r\n", writer.result.c_str());
}

TEST(ReadRedisValue, Array) {
    RedisValue val;

    StringReader reader;

    reader.input = "*4\r\n:10\r\n+lol\r\n-Permission denied\r\n$4\r\nabcd\r\n";
    ReadRedisValue(&reader, &val);

    //auto bulk = boost::get<std::vector<char>>(boost::get<std::vector<RedisValue>>(val)[3]);
    //std::string tmp(bulk.begin(), bulk.end());
    EXPECT_EQ(10, boost::get<int64_t>(boost::get<std::vector<RedisValue>>(val)[0]));
    EXPECT_STREQ("lol", boost::get<std::string>(boost::get<std::vector<RedisValue>>(val)[1]).c_str());
    EXPECT_STREQ("Permission denied", boost::get<RedisError>(boost::get<std::vector<RedisValue>>(val)[2]).msg.c_str());
    EXPECT_TRUE((std::vector<char>{'a', 'b', 'c', 'd'} == boost::get<std::vector<char>>(boost::get<std::vector<RedisValue>>(val)[3])));

    reader.input = "*0\r\n";
    ReadRedisValue(&reader, &val);

    EXPECT_EQ(0, boost::get<std::vector<RedisValue>>(val).size());
}








