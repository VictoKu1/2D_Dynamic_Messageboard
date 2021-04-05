#pragma once
#include <iostream>
#include "Board.hpp"
#include <map>
#include <string>
#include <stdexcept>
using namespace std ;
using namespace ariel::Direction ;
namespace ariel {
    const Direction horizontal = Direction::Horizontal;
    const Direction vertical = Direction::Vertical; 
    void Board::post(int row, int column, Direction direction, std::string message) {
        if(direction == horizontal){
            for(int i=0; i<message.length();i++){
                if(board.at(row) == null){
                    board.at(row) = new std::map<int,char>();                    
                }                
                board.at(row).oprator[](column+i)=message.at[i];
            }
            return;
        }
        if(direction == vertical){
            for(int i=0; i<message.length();i++){
                if(board.at(column) == null){
                    board.at(column) = new std::map<int,char>();                    
                }                
                board.at(row).oprator[](row+i)=message.at[i];
            }
            return;
        }
        throw std::invalid_argument{"Invalid direction ."};
    }    
    std::string Board::read(int row, int column, Direction direction, int length) {
        return "";
    }
    void Board::show() {

    }
}
