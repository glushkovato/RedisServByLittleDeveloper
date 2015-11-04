#include "redis.h"

#include <gtest/gtest.h>

TEST(RedisValue, Construct) {
    RedisValue integer = 10;
    RedisValue string = "abcd";
    RedisValue error = RedisError("Permission denied");
    RedisValue array = std::vector<RedisValue>{integer, string, error};
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

TEST(WriteRedisValue, Array) {
    RedisValue integer = 10;
    RedisValue string = "lol";
    RedisValue error = RedisError("Permission denied");
    RedisValue array = std::vector<RedisValue>{integer, string, error};

    StringWriter writer(1024);
    WriteRedisValue(&writer, array);
    writer.flush();

    EXPECT_STREQ("*3\r\n:10\r\n+lol\r\n-Permission denied\r\n", writer.result.c_str());
}

TEST(ReadRedisValue, Array) {
    RedisValue val;

    StringReader reader;

    reader.input = "*3\r\n:10\r\n+lol\r\n-Permission denied\r\n";
    ReadRedisValue(&reader, &val);

    EXPECT_EQ(10, boost::get<int64_t>(boost::get<std::vector<RedisValue>>(val)[0]));
    EXPECT_STREQ("lol", boost::get<std::string>(boost::get<std::vector<RedisValue>>(val)[1]).c_str());
    EXPECT_STREQ("Permission denied", boost::get<RedisError>(boost::get<std::vector<RedisValue>>(val)[2]).msg.c_str());
}








