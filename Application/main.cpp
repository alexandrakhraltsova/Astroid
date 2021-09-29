#include <iostream>
#include <cmath>
#include "/Users/alexandrakhraltsova/Desktop/Prog2/Library/astroid.hpp"

int main(){
    Prog2::Astroid a(-2, 1, 2);
    std::cout << "Your astroid is:" << std::endl;
    std::cout << "x^(2/3) + y^(2/3) = " << pow(a.getR(), 2.0/3.0) << std::endl;
    std::cout << "area: " << a.area() << std::endl;
    std::cout << "Curve length: " << a.curve_length() << std::endl;
    std::cout << "Enter the angle: " << std::endl;
    double t = Prog2::getDouble();
    if (t == -1)
        return 0;
    Prog2::check_t(t);
    std::cout << "Arc length: " << a.arc_lenght(t) << std::endl;
    std::cout << "Radius of curvature: " << a.radius_of_curvature(t) << std::endl;
    std::cout << "Coordinate values: x = " << a.coordinate_valueX(t) << ", y = " << a.coordinate_valueY(t) << std::endl;
    std::cout << "Enter x for calculate value y(x)" << std::endl;
    double x;
    double res;
    x = Prog2::getDouble();
    if (t == -1)
        return 0;
    res = a.value_at_point(x);
    try{
        std::cout << "y = " << res << std::endl;
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
