cmake_minimum_required(VERSION 3.27)
project(c_cipher_machine C)

set(CMAKE_C_STANDARD 11)

add_executable(c_cipher_machine
        main.c
        cipher.h
        cmdline.h
        cipher.c
        cmdline.c)
