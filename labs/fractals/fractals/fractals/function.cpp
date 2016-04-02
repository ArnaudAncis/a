#include "function.h"
#include <functional>

std::function<double(double)> linear(double x1, double y1, double x2, double y2)
{
    double m = (y2 - y1) / (x2 - x1);
    double q = (x2 * y1 - x1 * y2) / (x2 - x1);

    return [m, q](double x) { return m * x + q; };
}

std::function<double(double)> linear(double y1, double y2)
{
    double m = y2 - y1;
    double q = y1;

    return [m, q](double x) { return m * x + q; };
}

std::function<double(double)> easeInOut(double y1, double y2)
{
    double a = 2 * (y1 - y2);
    double b = -3 * (y1 - y2);
    double c = 0;
    double d = y1;

    return[a, b, c, d](double x) { return a * pow(x, 3) + b * pow(x, 2) + c * x + d; };
}

std::function<double(double)> constant(double y)
{
    return[y](double x){ return y; };
}
