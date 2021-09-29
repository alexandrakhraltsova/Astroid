#ifndef astroid_hpp
#define astroid_hpp
#define _USE_MATH_DEFINES

#include <iostream>
#include <stdio.h>
#include <cmath>

namespace Prog2{
    class Astroid{
    private:
        double x, y;
        double r;
    public:
        Astroid(double x0, double y0, double r0);
        Astroid& setX(const double &x0){ x = x0; return *this; };
        Astroid& setY(const double &y0){ y = y0; return *this; };
        Astroid& setR(double r0);
        double getX() const{ return x; }
        double getY() const{ return y; }
        double getR() const{ return r; }
        double curve_length() const{
            return 24 * r;
        }
        double area() const{
            return 6 * M_PI * r * r;
        }
        double arc_lenght(double t) const;
        double radius_of_curvature(double t) const;
        double coordinate_valueX(double t) const;
        double coordinate_valueY(double t) const;
        double value_at_point(double x) const;
    };

    inline double getDouble(){
        double a;
        std::cin >> a;
        if (std::cin.eof())
            return -1;
        while (!std::cin.good() || a < 0)
        {
            std::cout << "Error! Enter again please:" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> a;
            
        }
        return a;
    };

    inline void check_t(double t){
        if (t < 0 || t > 1.57)
            throw std::invalid_argument("Invalid angle");
    };
}

#endif /* astroid_hpp */
