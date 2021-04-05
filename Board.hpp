#pragma once
#include <string>
#include "Direction.hpp"
#include <map>
namespace ariel {
    class Board {
        std::map<int,std::map<int,char>> board ;
    public:
        Board(){
            board = new std::map<int,std::map<int,char>>() ;
        }
        ~Board() { 
            delete board ;
        }
        void post(uint row, uint column, Direction direction, std::string message);
        std::string read(uint row, uint column, Direction direction, int length);
        void show();
    };
}