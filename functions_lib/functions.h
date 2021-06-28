#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void initShapesMap();

static inline int skip_prefix(const char *str, const char *prefix,
                              const char **out);

double strToD2(char *str, bool &isError);

bool process(int argc, const char **argv);

double circleSquare(double radius);

double rectangleSquare(double a, double b);

double triangleSquare(double a, double h);

#endif /* FUNCTIONS_H */
