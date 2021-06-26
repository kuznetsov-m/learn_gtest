1. create `build` dir
2. exec from build dir `cmake ..`
3. `cmake --build .` or `make`
4. from comand palet `CMake: Run Tests` or from terminal `CTest`
5. check compiled program `./my_program`

# Notes
gtest_force_shared_crt - googletest variable (check it in CMakeCache)

run one of tests (not working for me on mac):

`./test/ExampleTests --gtest_filter=ExampleTests2*`

# Links
- [gtest_tutorial](https://youtu.be/Lp1ifh9TuFI)
- [tell cmake which compiler it should use](https://stackoverflow.com/a/63606463/10504918)