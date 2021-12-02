cmake_minimum_required(VERSION 3.0.0)
project(Noud VERSION 1.0.0)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_library(Noud src/noud.cpp)
set_target_properties(Noud PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
