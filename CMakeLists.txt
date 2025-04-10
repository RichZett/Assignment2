cmake_minimum_required(VERSION 3.20)

# Set project
project(Assignment2 VERSION 2.0 LANGUAGES C)

# Add the working directory folder to the build
add_subdirectory(Assignment2Lib)

# Generate variables with set of libs and include folders
# Dependencies are automatically set
list(APPEND EXTRA_LIBS Assignment2Lib) 
list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR}/Assignment2Lib") 

# Set source folder variable and add it in directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${SRC_DIR})

# ======== UNIT TESTS ========

# Add Unity test source
set(TEST_SRC ${SRC_DIR}/tests/test_runner.c)

# Add test executable
add_executable(runTests
    ${TEST_SRC}
    ${CMAKE_SOURCE_DIR}/Unity/src/unity.c  
)

# Include directories for the test
target_include_directories(runTests PRIVATE
    ${SRC_DIR}
    ${CMAKE_SOURCE_DIR}/Unity/src
    ${CMAKE_SOURCE_DIR}/Assignment2Lib
)

# Link any necessary libraries (like Assignment2Lib)
target_link_libraries(runTests PRIVATE ${EXTRA_LIBS})

# Optionally integrate with CTest
enable_testing()
add_test(NAME AllTests COMMAND runTests)

# Set target compile options
target_compile_options(runTests PRIVATE -Wall -Wextra -Wpedantic)