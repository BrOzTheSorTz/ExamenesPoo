cmake_minimum_required(VERSION 3.20)
project(PooFusion_git)

set(CMAKE_CXX_STANDARD 20)

FILE(GLOB SOURCE_FILES *.cpp)

ADD_EXECUTABLE(a.exe ${SOURCE_FILES} TorreDeControl.cpp TorreDeControl.h)
