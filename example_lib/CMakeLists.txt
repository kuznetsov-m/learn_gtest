set(
    Headers
    example.hpp
    functions.h
)

set(
    Sources
    example.cpp
    functions.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

target_include_directories(${This} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")