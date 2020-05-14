cmake_minimum_required(VERSION 3.16)
project(P3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(P3
        book.txt
        CPU.c
        cpu.h
        driver.c
        list.c
        list.h
        Makefile
        pri-schedule.txt
        README.md
        rr-schedule.txt
        schedule.txt
        schedule_fcfs.c
        schedulers.h
        task.h schedule_sjf.c schedule_priority.c schedule_rr.c)
