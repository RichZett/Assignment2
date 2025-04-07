# Assignment2Lib/CMakeLists.txt

# Define source files
set(Assignment2Lib_SOURCES
    cmdproc.c
)

# Create the library
add_library(Assignment2Lib STATIC ${Assignment2Lib_SOURCES})

# Set the include directories for this library
target_include_directories(Assignment2Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
