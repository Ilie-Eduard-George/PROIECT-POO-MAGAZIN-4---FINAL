cmake_minimum_required(VERSION 3.20)

project(ProiectPOO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(ProiectPOO
        main.cpp
        src/Magazin.cpp
        src/Produs.cpp
        src/Racheta.cpp
        src/Incaltaminte.cpp
        src/Imbracaminte.cpp
        src/Cos.cpp
        src/Client.cpp
)