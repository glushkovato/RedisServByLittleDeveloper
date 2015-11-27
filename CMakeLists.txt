project(hse-sample-project)
#cmake_minimum_required(VERSION 2.8)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

include_directories(.)

add_library(redis
        protocol/redis.cpp
        protocol/reader.cpp
        protocol/writer.cpp
        server/listener.cpp server/listener.h server/socket.cpp server/socket.h server/cmd.cpp server/cmd.h server/server.cpp server/server.h server/table.cpp server/table.h server/testserver.cpp server/server.c.h)

add_executable(redis-server
  main.cpp
)
target_link_libraries(redis-server redis pthread)

include_directories(contrib)

add_executable(run_test
  contrib/gmock-gtest-all.cc
  contrib/gmock_main.cc
  test/redis_test.cpp
        server/listener.cpp server/listener.h server/socket.cpp server/socket.h server/cmd.cpp server/cmd.h server/server.cpp server/server.h server/table.cpp server/table.h)
target_link_libraries(run_test redis pthread)
