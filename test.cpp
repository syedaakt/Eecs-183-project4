/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Syeda Shahriah-Akther
 * Syedaakt
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Point();
void test_Color();
void test_Line();
void test_Triangle();
void test_Circle();
void test_Rectangle();
void test_pics();

void startTests() {
    test_Point();
    test_Color();
    test_Line();
    test_Triangle();
    test_Circle();
    test_Rectangle();
    test_pics();
    
    return;
}

void test_Point() {
    // test of default constructor
    cout << "testing Point.cpp" << endl;
    Point pt1;
    pt1.setX(15);
    cout << "Expected: (15,0), actual :" << pt1 << endl;
    Point p1(.5 ,.7);
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);
    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
}
void test_Color(){
    cout << "testing Color.cpp" << endl;
    Color c1;
    c1.setRed(-100);
    c1.setGreen(2000);
    c1.setBlue(255);
    cout << "Expected: 0,255,255 Expected: "
    << c1.getRed() << "," << c1.getGreen() << "," << c1.getBlue() << endl;
    
    Color c2(10, 0, 55);
    cout <<"Expected 10 0 55 Actual: "<< c2 << endl;
}

void test_Line(){
    cout << "testing Line.cpp" << endl;
    Line l1;
    Point pt1(-5, 6);
    Point pt2(9,100);
    Color blue;
    l1.setStart(pt1);
    l1.setEnd(pt2);
    l1.setColor(blue);
    cout << l1.getStart() << " " << l1.getEnd() << " " << l1.getColor()
    << endl;
    Line l2(pt1, pt2, blue);
    cout << l2 << endl;
    
    
}
void test_Triangle(){
    cout << "testing Triangle.cpp" << endl;
    Point v1(-2,10);
    Point v2(2,5);
    Point v3(8,100);
    Color c1(-1, 9, 256);
    Color c2(0, 8, 9);
    Color c3(40, 50, 255);
    Triangle t1(v1, v2, v3, c1);
    cout << t1 << endl;
    Triangle t2(v1, c1, v2, c2, v3, c3);
    cout << t2 << endl;
    Triangle t3;
    t3.setVertexOne(v1);
    t3.setVertexTwo(v2);
    t3.setVertexThree(v3);
    t3.setVertexOneColor(c1);
    t3.setVertexTwoColor(c2);
    t3.setVertexThreeColor(c3);
    cout << t3.getVertexOne() << " " << t3.getVertexTwo() << " "
    << t3.getVertexThree() << " " << t3.getVertexOneColor() << " "
    << t3.getVertexTwoColor() << " " << t3.getVertexThreeColor() << endl;
    
   
}
void test_Circle(){
    cout << "testing Circle.cpp" << endl;
    Point center1(55,66);
    Point center2(-1, 100);
    Color C1;
    int radius1 = 7;
    Circle c1(center1, -9, C1);
    cout << c1 << endl;
    Circle c2(center2, radius1, C1);
    cout << c2 << endl;
    Circle c3;
    c3.setCenter(center2);
    c3.setRadius(-2);
    c3.setColor(C1);
    cout << c3.getCenter() << " " << c3.getRadius() << " " << c3.getColor()
    << endl;

}
void test_Rectangle(){
    cout << "testing Rectangle.cpp" << endl;
    Point p1(3, 500);
    Point p2(-3,5);
    Point p3(0,255);
    Point p4(99,100);
    Color c1(-3, 5, 256);
    Color c2;
    Color c3;
    Color c4;
    Rectangle r1 (p1, p2, c1);
    cout << r1 << endl;
    Rectangle r2(p3, p4, c1, c2, c3, c4);
    cout << r2 << endl;
    Rectangle r3;
    r3.setStart(p3);
    r3.setEnd(p4);
    r3.setColor(c3);
    cout << r3.getStart() << " " << r3.getEnd() << " " << r3.getColorTopLeft()
    << endl;
}
void test_pics(){
    
}


