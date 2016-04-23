#ifndef FUNCTION_H
#define FUNCTION_H

#include <functional>
#include <memory>

std::function<double(double)> linear(double x1, double y1, double x2, double y2);
std::function<double(double)> linear(double y1, double y2);
std::function<double(double)> easeInOut(double y1, double y2);
std::function<double(double)> constant(double y);
std::function<double(double)> gauss(double center, double slenderness);

template<typename R, typename T>
std::function<R(T)> scaleDomain(std::function<R(T)> f, double factor)
{
    return[f, factor](double x) { return f(x / factor); };
}

#endif