cmake_minimum_required(VERSION 3.24)
project(Projet C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet
        regle.c
        regle.h base_connaissance.h base_connaissance.c main.c)
