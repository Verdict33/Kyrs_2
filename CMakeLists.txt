cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        diskretka/otnochenia_not.c
        diskretka/otnochenia_not.h
        diskretka/relation.c
        diskretka/relation.h)
