cmake_minimum_required(VERSION 3.22)
project(EDD_Bench_Press_Follower C)

set(CMAKE_C_STANDARD 11)

add_executable(EDD_Bench_Press_Follower
        coopers-code.c
        Follow-code.c move-up.c)
