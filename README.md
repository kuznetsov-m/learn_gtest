[![Testing](https://github.com/kuznetsov-m/learn_gtest/actions/workflows/test.yml/badge.svg?branch=master)](https://github.com/kuznetsov-m/learn_gtest/actions/workflows/test.yml)

# App cli keys
```
--shape=[circle, rectangle, triangle] [int values]

example:
--shape=circle [radius_int_value]
--shape=rectangle [a_int_value] [b_int_value]
--shape=triangle [a_int_value] [h_int_value]
```

# CMake build
1. create `build` dir
2. exec from build dir `cmake ..`
3. `cmake --build .` or `make`
4. from VSCode Command Palette `CMake: Run Tests` or from terminal `CTest`
5. check compiled program `./my_program`

# Notes
Since gtest is intended for testing libraries (we cannot test code from an executable project). Then all the methods for the application were moved to the example_lib library.

gtest_force_shared_crt - googletest variable (check it in CMakeCache)

run one of tests (not working for me on mac):

`./test/ExampleTests --gtest_filter=ExampleTests2*`

# Links
- [gtest_tutorial](https://youtu.be/Lp1ifh9TuFI)
- [gtest-demo github repo](https://github.com/bast/gtest-demo)
- [tell cmake which compiler it should use](https://stackoverflow.com/a/63606463/10504918)
