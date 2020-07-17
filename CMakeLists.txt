cmake_minimum_required(VERSION 3.16)
project(LabDiPro)

set(CMAKE_CXX_STANDARD 14)

add_executable(LabDiPro main.cpp observer.h subject.h chat.cpp chat.h user.cpp user.h message.cpp message.h)