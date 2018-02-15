cmake_minimum_required(VERSION 3.9)
project(SingleLinkedListLib C)

set(CMAKE_C_STANDARD 99)

add_library(SingleLinkedListLib SHARED library.c library.h)