cmake_minimum_required(VERSION 3.24)
project(Projet C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet
        regle.c
        regle.h base_connaissance.h base_connaissance.c main.c base_fait.h base_fait.c moteur_inference.h moteur_inference.c)
