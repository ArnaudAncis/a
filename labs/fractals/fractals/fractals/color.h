#ifndef COLOR_H
#define COLOR_H

#include "function.h"

namespace imaging
{
    struct color final
    {
        double r, g, b;

        color() : color(0, 0, 0) { }

        color(double r, double g, double b)
            : r(r), g(g), b(b) { }

        void clamp();
        color clamped() const;
    };

    namespace colors
    {
        inline color black() { return color{ 0, 0, 0 }; }
        inline color white() { return color{ 1, 1, 1 }; }
        inline color red()   { return color{ 1, 0, 0 }; }
        inline color green() { return color{ 0, 1, 0 }; }
        inline color blue()  { return color{ 0, 0, 1 }; }
    }

    inline std::function<color(double)> color_function(std::function<double(double)> r, std::function<double(double)> g, std::function<double(double)> b)
    {
        return[r, g, b](double x) { return color(r(x), g(x), b(x)); };
    }
}

#endif