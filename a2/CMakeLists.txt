cmake_minimum_required(VERSION 2.8)
project(ece650-a2)

set (CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

add_executable(ece650-a2 ece650-a2.cpp)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(ece650-a2 Threads::Threads)
