set(
    Headers
    example.hpp
)

set(
    Sources
    example.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

target_include_directories(${This} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")