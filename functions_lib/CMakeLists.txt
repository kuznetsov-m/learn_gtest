set(
    Headers
    functions.h
)

set(
    Sources
    functions.cpp
)

add_library(${lib_name} STATIC ${Sources} ${Headers})

target_include_directories(${lib_name} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")