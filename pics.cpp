/**
 * pics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Syeda Shahriah-Akther
 * Syedaakt
 *
 *  Implementing functions calling all classes
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"


void printOpener();
void printCloser();
void printMenu();
string openFile(ifstream& ins);
string tolower(string str);
void loadFile(Graphics& drawer);
void writeFile(const Graphics& drawer);
void coolPics()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
    
    return;
}

void writeFile(const Graphics& drawer) {
    string fileN;
    //reads in file name
    cin >> fileN;
    //concatenates filename with .bmp
    fileN += ".bmp";
    //writes image to file
    drawer.writeFile(fileN);
    cout << "[Wrote " << fileN << "]" << endl;
}

void loadFile(Graphics& drawer) {
    //opens file
    ifstream file;
    string fileName = openFile(file);
    char shape;
    string error;
    
    //reads the first letter in each line of the file
    while (file >> shape) {
        //draws circle
        if (shape == 'C') {
            Circle cir;
            file >> cir;
            cir.draw(drawer);
        }
        //draws line
        else if (shape == 'L') {
            Line line;
            file >> line;
            line.draw(drawer);
        }
        //draws rectangle
        else if (shape == 'R') {
            Rectangle rec;
            file >> rec;
            rec.draw(drawer);
        }
        //draws triangle
        else if (shape == 'T') {
            Triangle tri;
            file >> tri;
            tri.draw(drawer);
        }
        // if first letter isnt C L R or T
        else {
            drawer.clear();
            cout << "Error in input file: " << shape << fileName
                 << error << endl;
        }
  }
    file.close();
    cout << "[Loaded " << fileName << "]" << endl;
}

string tolower(string str) {
    //returns the alhabetic letters in all lowercase
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}


// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
