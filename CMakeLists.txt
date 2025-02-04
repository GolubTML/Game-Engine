cmake_minimum_required(VERSION 3.10)

project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
include_directories("libs/include")
include_directories("C:/Users/lena/freetype/include")

add_executable(GameEngine src/main.cpp)

target_link_libraries(GameEngine OpenGL::GL)