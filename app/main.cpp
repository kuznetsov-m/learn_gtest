#include <iostream>
#include <example.hpp>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip> // std::setprecision
#include <string.h> // strcmp

enum Shape {
    none,
    circle,
};

std::map<std::string, Shape> shapesMap;

void initShapesMap() {
    shapesMap["circle"] = Shape::circle;
}

bool show_parameters = false;
static Shape shape = Shape::none;
static double radius = 0;

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

// return error arg count
//        -1 - sucsess
int readArgs(int argc, char **argv) {
    const char *shape_value = "";

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        const char *v;

        if (!strcmp(arg, "--show_parameters")) {
            show_parameters = true;
            continue;
        }
        if (skip_prefix(arg, "--shape=", &v)) {
            shape_value = v;
            continue;
        }
        if (skip_prefix(arg, "--radius=", &v)) {
            radius = std::atof(v);
            continue;
        }

        // unknown argument
        return i;
    }

    if (shapesMap.find(std::string(shape_value)) != shapesMap.end()) {
         shape = shapesMap.at(std::string(shape_value));
    }

    return -1;
}

// argc - ARGument Count
// argv - ARGument Vector
int main(int argc, char **argv) {
    initShapesMap();

    auto errorArgc = readArgs(argc, argv);
    if (errorArgc > 0) {
        std::cout << "Unknown argument: " << argv[errorArgc] << std::endl;
        return 0;
    }

    if (show_parameters) {
        std::cout << "show_parameters: " << std::boolalpha << show_parameters << std::endl;
        std::cout << "shape: " << shape << std::endl;
        std::cout << "radius: " << radius << std::endl;
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    //or C++20 std::format
    //std::cout << std::format("{:.2}\n", circle_square(radius));

    switch (shape) {
    case Shape::circle:
        std::cout << "Square: " << circleSquare(radius) << std::endl;
        break;
    case Shape::none:
    default:
        std::cout << "shape parameter not specified. Use --shape=[shape] key" << std::endl;
        return 0;
    }

    return 0;
}
