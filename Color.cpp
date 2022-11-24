/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Syeda Shahriah
 * syedaakt
 *
 * Implementing Color class definition, represents the color of the pixels
 */

#include "Color.h"

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

//checks if the color values are in range, if yes it sets its values
Color::Color(int redVal, int greenVal, int blueVal){
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

//sets red
void Color::setRed(int redVal){
    red = checkRange(redVal);
    return;
}

int Color::getRed() {
    return red;
}

//sets green
void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
    return;
}

int Color::getGreen(){
    return green;
}

//sets blue
void Color::setBlue(int blueVal){
    blue = checkRange(blueVal);
    return;
}

int Color::getBlue(){
    return blue;
}

// reads in color vals, sets the vals in rgb order and checks valid range
void Color::read(istream& ins){
    int RED, GREEN, BLUE;
    ins >> RED >> GREEN >> BLUE;
    setRed(RED);
    setGreen(GREEN);
    setBlue(BLUE);
}

//writes the vals in rgb order
void Color::write(ostream& outs){
    outs << red << " " << green << " " << blue;
}

//checks if the color vals are in order
int Color::checkRange(int val) {
    if (val >= 0 && val <= 255){
        return val;
    }
    else if (val < 0) {
        return 0;
    }
    else {
        return 255;
    }
    
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
