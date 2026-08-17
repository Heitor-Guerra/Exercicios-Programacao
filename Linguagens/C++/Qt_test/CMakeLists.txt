cmake_minimum_required(VERSION 3.16)
project(Qt_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_compile_options(-Wall -Werror)
file(GLOB_RECURSE main src/*.cpp)
add_executable(${PROJECT_NAME} ${main})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
