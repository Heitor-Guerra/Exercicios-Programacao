cmake_minimum_required(VERSION 3.10)
project(read)

file(GLOB_RECURSE main src/*.cpp src/*.h)

add_executable(main ${main})

target_compile_options(main PUBLIC -Wall -Wextra)
