cmake_minimum_required(VERSION 3.13)


add_library(lib INTERFACE)
        target_include_directories(lib INTERFACE .)


# These declaration works for both UNIX/Win and bare metal. 
        target_sources(lib INTERFACE 
                        calc.cpp)
