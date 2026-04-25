cmake_minimum_required(VERSION 3.20)
project(notepadzero)

set(CMAKE_C_STANDARD 11)

add_executable(notepadzero main.c)

target_link_libraries(notepadzero
        user32
        shell32
        powrprof
)