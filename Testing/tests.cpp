//
//  Testing.cpp
//  Prog2
//
//  Created by Alexandra Khraltsova on 23.09.2021.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <gtest/gtest.h>
#include "/Users/alexandrakhraltsova/Desktop/Prog2/Library/astroid.hpp"

TEST(AstroidConstructor, InitConstructors){
    Prog2::Astroid a1(-1, -2, 8);
    ASSERT_EQ(-1, a1.getX());
    ASSERT_EQ(-2, a1.getY());
    ASSERT_EQ(8, a1.getR());
}

TEST(AstroidConstructor, TestException){
    ASSERT_ANY_THROW(Prog2::Astroid(3, 5, -2));
}

TEST(AstroidMethods, Setters){
    Prog2::Astroid a(0, 0, 1);
    a.setX(4);
    a.setY(9);
    ASSERT_EQ(4, a.getX());
    ASSERT_EQ(9, a.getY());
    a.setX(-4);
    a.setY(-9);
    ASSERT_EQ(-4, a.getX());
    ASSERT_EQ(-9, a.getY());
    a.setR(2);
    ASSERT_EQ(2, a.getR());
    ASSERT_ANY_THROW(a.setR(-5));
}

TEST(AstroidMethods, Parametrs){
    Prog2::Astroid a(2, 3, 1);
    const double err = 0.00001;
    ASSERT_NEAR(6 * M_PI, a.area(), err);
    ASSERT_NEAR(24, a.curve_length(), err);
    ASSERT_EQ(0, a.value_at_point(1));
    ASSERT_NEAR(0.51542, a.value_at_point(0.5), err);
    ASSERT_ANY_THROW(a.value_at_point(6));
    ASSERT_NEAR(0, a.arc_lenght(0), err);
    ASSERT_NEAR(1.5, a.arc_lenght(M_PI/6), err);
    ASSERT_NEAR(0, a.radius_of_curvature(M_PI/2), err);
    ASSERT_EQ(6, a.radius_of_curvature(M_PI/4));
    ASSERT_NEAR(1.41421, a.coordinate_valueX(M_PI/4), err);
    ASSERT_NEAR(4, a.coordinate_valueX(0), err);
    ASSERT_NEAR(1.41421, a.coordinate_valueY(M_PI/4), err);
    ASSERT_NEAR(0, a.coordinate_valueY(0), err);
}


int tmain(int argc, char * argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
