# Set the source files that make up the library
set(Assignment2Lib
 cmdproc.h cmdproc.c
)
# Set the library type (can be static or dynamic )
set(LIB_TYPE STATIC)

# Create the library
add_library (Assignment2Lib ${LIB_TYPE} ${Assignment2Lib})
