cmake_minimum_required(VERSION 4.0)
project(ez_cui C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(ez_cui STATIC src/ez_cui.c
        include/helper.h
        include/util.h
        src/util.c)
link_libraries(ez_cui)
add_executable(tests example/main.c)