#include <iostream>
#include <example.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> // std::setprecision
#include <string.h> // strcmp

static inline int skip_prefix(const char *str, const char *prefix,
                              const char **out)
{
    do {
        if (!*prefix) {
            *out = str;
            return 1;
        }
    } while (*str++ == *prefix++);
    return 0;
}

bool show_parameters = false;
static const char *shape;
static int radius = 0;

// argc - ARGument Count
// argv - ARGument Vector
int main(int argc, char **argv) {

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        const char *v;

        if (!strcmp(arg, "--show_parameters")) {
            show_parameters = true;
            continue;
        }
        if (skip_prefix(arg, "--shape=", &v)) {
            shape = v;
            continue;
        }
        if (skip_prefix(arg, "--radius=", &v)) {
            radius = atoi(v);
            continue;
        }

        std::cout << "Unknown argument: " << arg << std::endl;
        return 0;
    }

    if (show_parameters) {
        std::cout << "show_parameters: " << std::boolalpha << show_parameters << std::endl;
        std::cout << "shape: " << shape << std::endl;
        std::cout << "radius: " << radius << std::endl;
    }

    if (!shape) {
        std::cout << "--shape key is missed" << std::endl;
        return 0;
    }

    if (strcmp(shape, "circle") == 0) {
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        //or C++20 std::format
        //std::cout << std::format("{:.2}\n", circle_square(radius));

        std::cout << "Square: " << circleSquare(radius) << std::endl;
    }
    else {
        std::cout << "Unknown shape: " << shape << std::endl;
    }

    return 0;
}
