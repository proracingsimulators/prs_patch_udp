cmake_minimum_required(VERSION 3.12)

project(Prs_Patch_Udp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Prs_Patch_Udp
    main.cpp
)

set(CMAKE_EXE_LINKER_FLAGS "-static")

target_link_libraries(Prs_Patch_Udp ws2_32)
