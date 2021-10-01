//
//  astroid.cpp
//  Prog2
//
//  Created by Alexandra Khraltsova on 19.09.2021.
//

#include <strstream>
#include <stdio.h>
#include <string.h>
#include "astroid.hpp"
using namespace Prog2;


Astroid::Astroid(double x0, double y0, double rad): x(x0), y(y0){
    if (rad < 0)
        throw std::runtime_error("invalid radius");
    r = rad;
}


Astroid& Astroid::setR(double r0)
{
    if (r0 < 0)
        throw std::runtime_error("invalid radius");
    r = r0;
    return *this;
}

double Astroid::arc_lenght(double t) const{
    double l;
    l = 6 * r * pow(sin(t), 2);
    return l;
}

double Astroid::radius_of_curvature(double t) const{
    double R;
    R = 6 * r * sin(2*t);
    return R;
}

double Astroid::coordinate_valueX(double t) const{
    double x1;
    x1 = 4 * r * pow(cos(t), 3);
    return x1;
}

double Astroid::coordinate_valueY(double t) const{
    double y1;
    y1 = 4 * r * pow(sin(t), 3);
    return y1;
}

double Astroid::value_at_point(double x) const{
    double res = pow(r, 2.0/3.0) - (pow(x, 2.0/3.0));
    if (res < 0)
        throw std::runtime_error("illegal argument x");
    res = pow(res, 2.0/3.0);
    return res;
}
