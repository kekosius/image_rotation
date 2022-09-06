cmake_minimum_required(VERSION 3.17)
project(image_rotation C)

set(CMAKE_C_STANDARD 11)
set(SRC main.c src/bmp.c src/util.c src/read_bmp.c src/rotate_bmp.c src/write_bmp.c src/file_io.c)

include_directories(${CMAKE_CURRENT_LIST_DIR}/inc/)

add_executable(image_rotation ${SRC})