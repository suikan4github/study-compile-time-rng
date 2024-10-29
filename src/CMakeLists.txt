add_executable(${PROJECT_NAME} main.cpp)

    target_link_libraries(${PROJECT_NAME}
                            lib)

if(NOT(${WIN32}) AND NOT (${UNIX})) # Is Target Pico? 
    # pull in common dependencies
    target_link_libraries(${PROJECT_NAME} pico_stdlib )

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(${PROJECT_NAME})

    # enable usb output, disable uart output
    pico_enable_stdio_usb(${PROJECT_NAME} 1)  # 1 enable, 0 disable
    pico_enable_stdio_uart(${PROJECT_NAME} 0) # 1 enable, 0 disable

endif() # (NOT(${WIN32}) AND NOT (${UNIX})) 

add_subdirectory(lib)
