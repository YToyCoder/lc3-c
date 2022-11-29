cmake_minimum_required(VERSION 3.23)
project(vm_lc3 C)

set(CMAKE_C_STANDARD 17)

add_executable(vm_lc3 main.c vm.h lc3.c load.c misc.h misc.c)
