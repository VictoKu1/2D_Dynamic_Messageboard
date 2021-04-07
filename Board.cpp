#include "Board.hpp"

using namespace std;
using namespace ariel;

namespace ariel {
    const Direction horizontal = Direction::Horizontal;
    const Direction vertical = Direction::Vertical;
    
    Board::Board(){
        board = new std::map<int,std::map<int,char>>() ;
        maxRw=0;
        maxCn=0;
    }

    Board::~Board() { 
        delete board ;
    }

    int Board::getRw() const{
        return maxRw;
    }

    int Board::getCn() const{
        return maxCn;
    }

    void Board::post(uint32_t row, uint32_t column, Direction direction, string message) {
        if(direction == horizontal){
            if(((int)row)+((int)message.length())>(maxRw)){
                (maxRw)=((int)row)+((int)message.length());
            }
            if(((int)column)>(maxCn)){
                (maxCn)=((int)column);
            }
            if((*board).find((int)row)==(*board).end()){
                map<int,char>rowN;
                (*board).insert({((int)row),rowN});
            }
            for(size_t i=0;i<message.length();i++){
                if((*board).at((int)row).find((int)column+((int)i))!=(*board).at((int)row).end()){
                    (*board).at((int)row).erase(((int)column)+((int)i));
                }
                    (*board).at((int)row).insert({((int)column)+((int)i),message[i]});
            }
            return;
        }
        if(direction == vertical){
            if(((int)row)>(maxRw)){
                (maxRw)=((int)row);
            }
            if(((int)column)+((int)message.length())>(maxCn)){
                (maxCn)=((int)column)+((int)message.length());
            }
            for(size_t i=0;i<message.length();i++){
                if((*board).find((int)row+((int)i))==(*board).end()){
                    map<int,char>rowN;
                    (*board).insert({((int)row)+((int)i),rowN});
                }
                if((*board).at(((int)row)+((int)i)).find((int)column)!=(*board).at((int)row).end()){
                    (*board).at(((int)row)+((int)i)).erase((int)column);
                }
                (*board).at(((int)row)+((int)i)).insert({((int)column),message[i]});
            }
            return;
        }
        throw invalid_argument{"Invalid direction ."};
    }

    char Board::charAt(int row, int column){
        if((*board).find(row)!=(*board).end()){
            if((*board).at(row).find(column)!=(*board).at(row).end()){
                return ((*board).at(row).at(column));
            }
        }
        return '_';
    }   

    string Board::read(uint32_t row, uint32_t column, Direction direction, uint32_t length) {
        string str ;
        if(direction==horizontal){
            for(int i=0;i<length;i++){
                str.push_back(Board::charAt(((int)row),((int)column)+((int)i)));
            }
            return str;
        }
        if(direction==vertical){
            for(int i=0;i<length;i++){
                str.push_back(Board::charAt(((int)row)+((int)i),((int)column)));
            }
            return str;
        }
        throw invalid_argument{"Invalid direction ."};
    }

    void Board::show() {
        for (const auto &row : *board){
            for (const auto &column : row.second){
                    cout << column.second;
            }
            cout << endl;
        }
    }
}
