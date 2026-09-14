# Godzilla Project
cmake_minimum_required(VERSION 3.10.0)
project(Godzilla VERSION 0.1.0 LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Escolha o tipo de build" FORCE)
endif()

add_executable(Godzilla src/main.cpp)

set_target_properties(Godzilla PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)