cmake_minimum_required(VERSION 3.17)
project(AlbionMaster)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlbionMaster main.cpp FindProcessId.cpp time.cpp logger.cpp op_in.cpp WriteMemory.cpp ReadMemory.cpp)