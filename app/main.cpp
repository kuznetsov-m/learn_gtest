#include <iostream>

#include <functions.h>

// argc - ARGument Count
// argv - ARGument Vector
int main(int argc, char **argv) {
    if (!process(argc, const_cast<const char **>(argv)))
        std::cout << "Incorrect arguments syntax" << std::endl;

    return 0;
}
