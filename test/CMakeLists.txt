cmake_minimum_required(VERSION 3.20)

set(This example_tests)

# -------------------------------------
# Download googletest
include(FetchContent)
FetchContent_Declare(gtest
    QUIET
    URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)
# -------------------------------------

set(
    Sources
    example_tests.cpp
    example_tests0.cpp
)

add_executable(${This} ${Sources})

# for #include <gtest/gtest.h>
target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(${This}
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )