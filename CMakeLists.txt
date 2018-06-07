cmake_minimum_required(VERSION 3.10)
project(regx_h C)

set(CMAKE_C_STANDARD 11)

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(regx_h STATIC
        src/regx.c src/regx.h)

target_include_directories(regx_h
        PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        )

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(regx_h_tests
        tests/test.c)

# link the new hello_library target with the hello_binary target
target_link_libraries(regx_h_tests
        PRIVATE
        regx_h
        )

############################################################
# Enable testing
############################################################

include(CTest)
enable_testing()

# add executable to test
add_test(NAME "regx_h_tests"
        COMMAND regx_h_tests)
