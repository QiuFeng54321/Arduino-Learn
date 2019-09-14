cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 17)

project(LightBlink)

function(proj PROJECT_NAME_A SKETCH_FILE)

    set(${PROJECT_NAME_A}_BOARD uno)
    # set(ARDUINO_CPU)

    # Define additional source and header files or default arduino sketch files
    # set(${PROJECT_NAME}_SRCS)
    set(${PROJECT_NAME_A}_HDRS User_Setup.h)

    ### Additional static libraries to include in the target.
    # set(${PROJECT_NAME}_LIBS)

    ### Main sketch file
    set(${PROJECT_NAME_A}_SKETCH ${SKETCH_FILE})

    ### Add project directories into the build
    # add_subdirectory()

    ### Additional settings to add non-standard or your own Arduino libraries.
    # For this example (libs will contain additional arduino libraries)
    # An Arduino library my_lib will contain files in libs/my_lib/: my_lib.h, my_lib.cpp + any other cpp files
    # link_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

    # For nested library sources replace ${LIB_NAME} with library name for each library
    # set(_RECURSE true)

    #### Additional settings for programmer. From programmers.txt
    # set(${PROJECT_NAME}_PROGRAMMER avrispmkii)
    set(${PROJECT_NAME_A}_PORT /dev/cu.usbmodem14201)
    # set(uno.upload.speed 9600)

    ## Verbose build process
    # set(${PROJECT_NAME}_AFLAGS -v)

    generate_arduino_firmware(${PROJECT_NAME_A})

endfunction()

proj(LightBlink-No-Off No_Off/light_blink_no_off.ino)

proj(LightBlink-Spread Spread/light_blink_spread.ino)