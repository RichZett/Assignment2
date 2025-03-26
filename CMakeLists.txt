cmake_minimum_required(VERSION 3.20)

# Set project
project(Assignment2 VERSION 1.0 LANGUAGES C)

# Add the working directory folder to the build
add_subdirectory(Assignment2Lib)

# Generate variables with set of libs and include folders
# Dependencies are automatically set
list(APPEND EXTRA_LIBS Assignment2Lib) 

list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR}/Assignment2Lib") 

# Set source folder variable and add it in directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${SRC_DIR})

# Collect all source files from the source folder
set(SOURCES ${SRC_DIR}/main.c)

# Set the executable
add_executable(exec ${SOURCES})

# Specify libraries or flags to use when linking a given target and/or its dependents
target_link_libraries(exec PUBLIC ${EXTRA_LIBS})

# Specifies include directories to use when compiling a given target
target_include_directories(exec PUBLIC ${EXTRA_INCLUDES})

# Set target compile options
target_compile_options(exec PRIVATE -Wall -Wextra -Wpedantic)
