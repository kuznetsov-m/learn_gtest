set(
    Headers
    example.hpp
)

set(
    Sources
    example.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})