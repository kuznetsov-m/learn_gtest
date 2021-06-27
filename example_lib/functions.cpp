#include "functions.h"

#include <iostream>
#include "example.hpp"
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip> // std::setprecision
#include <string.h> // strcmp
#include <cstdlib> // strtod
#include <cerrno> // errno

enum Shape {
    none,
    circle,
    rectangle,
    triangle
};

std::map<std::string, Shape> shapesMap;

void initShapesMap() {
    shapesMap["circle"] = Shape::circle;
    shapesMap["rectangle"] = Shape::rectangle;
    shapesMap["triangle"] = Shape::triangle;
}

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

double strToD(const char *str, bool &isError) {
    char *e;
    errno = 0;
    auto v = std::strtod(str, &e);

    if (*e != '\0' ||  // error, we didn't consume the entire string
        errno != 0 )   // error, overflow or underflow
    {
        isError = true;
    }
    else {
        isError = false;
    }
    return v;
}

bool process(int argc, const char **argv) {
    initShapesMap();

    bool result = false;

    if (argc <= 1) {
        return result;
    }

    const char *v;
    auto shape = Shape::none;
    if (skip_prefix(argv[1], "--shape=", &v)) {
        if (shapesMap.find(std::string(v)) != shapesMap.end()) {
             shape = shapesMap.at(std::string(v));
        }
    }

    std::vector<double> values;

    for (int i = 2; i < argc; ++i) {
        auto isError = false;
        auto v = strToD(argv[i], isError);
        if (!isError)
            values.push_back(v);
        else
            return result;
    }

    // setup double display format
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    //or C++20 std::format
    //std::cout << std::format("{:.2}\n", circle_square(radius));

    switch (shape) {
    case Shape::circle:
        if (values.size() >= 1) {
            std::cout << "Square: " << circleSquare(values.at(0)) << std::endl;
            result = true;
        }
        break;
    case Shape::rectangle:
        if (values.size() >= 2) {
            std::cout << "Square: " << rectangleSquare(values.at(0), values.at(1)) << std::endl;
            result = true;
        }
        break;
    case Shape::triangle:
        if (values.size() >= 2) {
            std::cout << "Square: " << triangleSquare(values.at(0), values.at(1)) << std::endl;
            result = true;
        }
        break;
    case Shape::none:
    default:
        break;
    }

    return result;
}
