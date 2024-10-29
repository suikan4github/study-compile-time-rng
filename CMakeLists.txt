# CMake 3.15 or newer is requried because of CMP0091.
cmake_minimum_required(VERSION "3.15")


# Compiler option
# GoogleTest requirest C++11 or later
set(CMAKE_CXX_STANDARD "17")
set(CMAKE_CXX_STANDARD_REQUIRED "ON")

# In the toplevel CMakeLists.txt, we can not use the
# $WIN or $Unix. To avoid this problem, we check the 
# Compile path string. If it contains arm-none-eabi, 
# We guess this is bare metal target. 

# Is compiler arm-none-eabi? 
string(FIND ${CMAKE_CXX_COMPILER} "arm-none-eabi" FOUNDPOS)
if( ${FOUNDPOS} GREATER "-1") # If yes, it is pico
    message(STATUS "Target is bare metal")
    # obtain pico-sdk from GIT
    # (note this can come from environment, CMake cache etc)
    set(PICO_SDK_FETCH_FROM_GIT on)

    # pico_sdk_import.cmake is a single file copied from this SDK
    # note: this must happen before project()
    include(pico_sdk_import.cmake)


    # initialize the Raspberry Pi Pico SDK
    pico_sdk_init()
endif() # string(FIND CMAKE_CXX_COMPILER "arm-none-eabi") GREATER_EQUAL 0 

# Pico SDK requires the project name must be set after
# including pico_sdk_import.cmake. On the other hand, CMake
# requires to set the project name at the toplevel. 
# So, we delcare here.  
project("app")

if( ${FOUNDPOS} LESS "0") # If yes, it is Windows or Linux
    message(STATUS "Target is Windows or Linux")

    # Unit test. 
    enable_testing()
    add_subdirectory("test")

endif() # string(FIND CMAKE_CXX_COMPILER "arm-none-eabi") GREATER_EQUAL 0 


# Subdirectories
add_subdirectory("src")

