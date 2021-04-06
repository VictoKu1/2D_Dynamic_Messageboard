#pragma once
#include <string>
#include "Direction.hpp"
#include <map>
#include <stdexcept>
#include <map>
#include <unistd.h>
#include <iostream>
const std::string range = "range";
const std::string selective ="selective";
const int INT_MAX = 2147483647;
const int INT_MIN = -2147483648; 
namespace ariel {
    class Board {
        std::map<int,std::map<int,char>>* board ;
        int maxRw;
        int maxCn;
    public:
        Board();
        ~Board();
        int getRw() const;
        int getCn() const;
        void post(uint32_t row, uint32_t column, Direction direction, std::string message);
        char charAt(int row, int column);
        std::string read(uint32_t row, uint32_t column, Direction direction, uint32_t length);
        void show();
    };
}
