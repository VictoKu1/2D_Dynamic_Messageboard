#pragma once
#include <string>
#include "Direction.hpp"
#include <map>
#include <stdexcept>
#include <map>
#include <unistd.h>
#include <iostream>
const int INT_MAX = 2147483647;
const int INT_MIN = -2147483648; 
namespace ariel {
    class Board {
        std::map<int,std::map<int,char>>* board ; //* 2D std::map which contains charecters as a central value, basically represends a dinamic matrix.
        int maxRw; //* Parameter which represends the farest row in the board which contains a value .
        int maxCn; //* Parameter which represends the farest column in the board which contains a value .
    public:
        Board(); //*Constructor which makes new object of a type 2D std::map which contains charecters as a central value.
        ~Board(); //*Destructor for the Board class, deletes only the 2D std::map due to its uniqness as the only allocated object.
        int getRw() const; //*Getter method which returns the farest row in the board which contains a value .
        int getCn() const; //*Getter method which returns the farest column in the board which contains a value .
        void post(uint32_t row, uint32_t column, Direction direction, std::string message); //*Putts a string message inside the board, the starting charecter is at (row,column), the direction (horizontal/vertical) is determined by the Direction enum object.
        char charAt(int row, int column); //*Returns a charecter which located on a specific location on the board, if the location is empty (uninitialized) the method returns an Underscore charecter .
        std::string read(uint32_t row, uint32_t column, Direction direction, uint32_t length); //*Returns a string of a specific length of a specific direction from a specific location.
        void show(); //*Prints the board using iterator.
    };
}
