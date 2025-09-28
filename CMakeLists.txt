cmake_minimum_required(VERSION 4.0)
project(ez_cui C)

set(CMAKE_C_STANDARD 11)

add_library(ez_cui STATIC src/ez_cui.c
        include/helper.h)
link_libraries(ez_cui)
add_executable(tests example/all_test.c)