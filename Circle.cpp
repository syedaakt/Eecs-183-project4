/**
 * Circle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Syeda Shahriah-Akther
 * Syedaakt
 *
 * Implementing class definition for Circle, creates a circle
 */

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;

Circle::Circle(){
}

//sets center, radius (must be positive), and color
Circle::Circle(Point pt, int r, Color c){
    center = pt;
    radius = checkRadius(r);
    color = c;
}

//sets the coordinates for the center
void Circle::setCenter(Point pt){
    center = pt;
    return;
}

Point Circle::getCenter(){
    return center;
}

//sets the radius value and makes sure it's positive
void Circle::setRadius(int r){
    radius = checkRadius(r);
    return;
}

int Circle::getRadius(){
    return radius;
}

//sets the color of the circle
void Circle::setColor(Color c){
    color = c;
    return;
}

Color Circle::getColor(){
    return color;
}

/**
 * Requires: ins is in good state.
 * Modifies: ins, center, radius, color.
 * Effects:  Read circle in form center radius color
 */
//reads in the circle information
void Circle::read(istream& ins){
    ins >> center >> radius >> color;
}

//writes the circle info
void Circle::write(ostream& outs){
    outs << center << " " << radius << " " << color;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();

    while (x >= y)
    {
        plot8points(x, y, c, drawer);

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();

    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);

    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
