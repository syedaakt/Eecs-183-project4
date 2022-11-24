/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Syeda Shahriah
 * Syedaakt
 *
 * Point class functions, represents a coordinate
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// TODO: implement two constructors, setX, getX, setY, getY, read, write, checkRange.

/**
 * Requires: Nothing.
 * Modifies: x, y.
 * Effects:  Default contructor. Sets point to origin (0,0).
 */
Point::Point() {
    x = 0;
    y = 0;
}
/**
 * Requires: Nothing.
 * Modifies: x, y.
 * Effects:  Constructs a point and sets x and y coordinates.
 * Note: you will want to implement the private
 *    member function checkRange() before
 *    implementing this one
 */
Point::Point(int xVal, int yVal){
    x = checkRange(xVal);
    y = checkRange(yVal);
}

/**
 * Requires: Nothing.
 * Modifies: x.
 * Effects:  Sets x coordinate.
 */
void Point::setX(int xVal) {
    x = checkRange(xVal);
    return; // do we need a return here?
}
/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns x coordinate.
 */
int Point::getX() {
    return x;
    //return x; ??
}

/**
 * Requires: Nothing.
 * Modifies: y.
 * Effects:  Sets y coordinate.
 */
void Point::setY(int yVal) {
    y = checkRange(yVal);
    return;
}
/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns y coordinate.
 */
int Point::getY() {
    return y;
    //return y; ??
}

/**
 * Requires: ins is in good state.
 * Modifies: ins, x, y.
 * Effects:  Reads point in form (x,y).
 */
void Point::read (istream& ins) {
    // "("
    char first;
    // ","
    char comma;
    // ")"
    char last;
    ins >> first >> x >> comma >> y >> last;
    return;
}
/**
 * Requires: outs is in good state.
 * Modifies: outs.
 * Effects:  Writes point in form (x,y).
 */
void Point::write(ostream& outs) {
    outs << "(" << checkRange(x) << "," << checkRange(y) << ")";
    // x y? or checkrange?
}

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:
 * Effects:  Returns val if val is in range [0,DIMENSION),
 *           otherwise returns the closest of 0 and DIMENSION - 1.
 */
// Checks if range of the point is between 0 and 99 or DIMENSION which is set to 100.
int Point::checkRange(int val) {
    //returns val if val is within [0,DIMENSION)
    if (val >= 0 && val < DIMENSION){
        return val;
    }
    //if val is equal to or greater than 100, returns 99
    else if (val >= DIMENSION) {
        return DIMENSION - 1;
    }
    //if val is less than 0, returns 0
    else if (val < 0) {
        return 0;
    }
    return 0;

}




// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
