cmake_minimum_required(VERSION 2.8)
project (logging_examples)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -Wall")

set(SRC_LIST examples/example1.cpp)
set(SRC_LIB src/logging.cpp)
include_directories(include)
add_library(logging STATIC ${SRC_LIB})
add_executable(examples ${SRC_LIST})

target_link_libraries(examples logging)
