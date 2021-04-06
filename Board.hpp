#pragma once
#include <string>
#include "Direction.hpp"
#include <map>
namespace ariel {
    class Board {
        std::map<int,std::map<int,char>>* board ;
    public:
        Board();
        ~Board();
        void post(uint32_t row, uint32_t column, Direction direction, std::string message);
        char charAt(int row, int column);
        std::string read(uint32_t row, uint32_t column, Direction direction, uint32_t length);
        void show();
    };
}