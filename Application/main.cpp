//
//  main.cpp
//  Prog2
//
//  Created by Alexandra Khraltsova on 19.09.2021.
//

#include <iostream>
#include <cmath>
//#include "/Users/alexandrakhraltsova/Desktop/Lab2/Library/astroid.hpp"
#include "astroid.hpp"

int main(){
    Prog2::Astroid a(-2, 1, 2);
    std::cout << "Your astroid is:" << std::endl;
    std::cout << "x^(2/3) + y^(2/3) = " << pow(a.getR(), 2.0/3.0) << std::endl;
    double t;
    int k;
        do {
            std::cout << "0. Exit" << std::endl;
            std::cout << "1. Set r" << std::endl;
            std::cout << "2. Get r" << std::endl;
            std::cout << "3. Curve length" << std::endl;
            std::cout << "4. Area" << std::endl;
            std::cout << "5. Arc length" << std::endl;
            std::cout << "6. Radius of curvature" << std::endl;
            std::cout << "7. Coordinate values" << std::endl;
            std::cout << "8. Value y(x)" << std::endl;
            std::cout << "Enter the command: ";
            k = Prog2::getDouble();
            switch(k) {
                case 0:
                    std::cout << "Exit!" << std::endl;
                    break;
                case 1:
                    double R;
                    std::cout << "Enter the radius that you want:" << std::endl;
                    R = Prog2::getDouble();
                    a.setR(R);
                    break;
                case 2:
                    std::cout << "r = " << a.getR() << std::endl;
                    std::cout << "R = " << 4 * a.getR() << std::endl;
                    break;
                case 3:
                    std::cout << "Curve length: " << a.curve_length() << std::endl;
                    break;
                case 4:
                    std::cout << "area: " << a.area() << std::endl;
                    break;
                case 5:
                    t = Prog2::SetAngle();
                    if (t == -1)
                        return 0;
                    std::cout << "Arc length: " << a.arc_lenght(t) << std::endl;
                    break;
                case 6:
                    t = Prog2::SetAngle();
                    if (t == -1)
                        return 0;
                    std::cout << "Radius of curvature: " << a.radius_of_curvature(t) << std::endl;
                    break;
                case 7:
                    t = Prog2::SetAngle();
                    if (t == -1)
                        return 0;
                    std::cout << "Coordinate values: x = " << a.coordinate_valueX(t) << ", y = " << a.coordinate_valueY(t) << std::endl;
                    break;
                case 8:
                    std::cout << "Enter x for calculate value y(x)" << std::endl;
                    double x;
                    double res;
                    x = Prog2::getDouble();
                    if (x == -1)
                        return 0;
                    res = a.value_at_point(x);
                    try{
                        std::cout << "y = " << res << std::endl;
                    }
                    catch(std::exception &ex)
                    {
                        std::cout << ex.what() << std::endl;
                    }
                    break;
                default:
                    std::cout << "Error! There is not such command!" << std::endl;
            }
        } while (k != 0 && k != -1);
    return 0;
}
