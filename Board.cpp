#include <iostream>
#include "Board.hpp"
#include <map>
#include <string>
#include <stdexcept>
using namespace std;
using namespace ariel;
namespace ariel {
    const Direction horizontal = Direction::Horizontal;
    const Direction vertical = Direction::Vertical; 
    Board::Board(){
            board = new std::map<int,std::map<int,char>>() ;
        }
    Board::~Board() { 
            delete board ;
        }
    void Board::post(uint32_t row, uint32_t column, Direction direction, std::string message) {
        if(direction == horizontal){
            if(!(*board).contains((int)row)){
                map<int,char>rowN;
                (*board).insert({((int)row),rowN});
            }
            for(size_t i=0;i<message.length();i++){
                if((*board).operator[]((int)row).contains((int)column+((int)i))){
                    (*board).at((int)row).erase(((int)column)+((int)i));
                }
                    (*board).at((int)row).insert({((int)column)+((int)i),message[i]});
            }
            return;
        }
        if(direction == vertical){
            for(size_t i=0;i<message.length();i++){
                if(!(*board).contains((int)row+((int)i))){
                    map<int,char>rowN;
                    (*board).insert({((int)row)+((int)i),rowN});
                }
                if((*board).at(((int)row)+((int)i)).contains((int)column)){
                    (*board).at(((int)row)+((int)i)).erase((int)column);
                }
                (*board).at(((int)row)+((int)i)).insert({((int)column),message[i]});
            }
            return;
        }
        throw std::invalid_argument{"Invalid direction ."};
    }     
    std::string Board::read(uint32_t row, uint32_t column, Direction direction, uint32_t length) {
        return "";
    }
    void Board::show() {

    }
}
