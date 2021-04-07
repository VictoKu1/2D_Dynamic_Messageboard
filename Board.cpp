//*Implementation of the board class.
#include "Board.hpp"
using namespace std;
using namespace ariel;
namespace ariel {
    const Direction horizontal = Direction::Horizontal;
    const Direction vertical = Direction::Vertical;
    
    //*Constructor which makes new object of a type 2D std::map which contains charecters as a central value. 
    Board::Board(){
        board = new std::map<int,std::map<int,char>>() ;
        maxRw=0;
        maxCn=0;
    }
    
    //*Destructor for the Board class, deletes only the 2D std::map due to its uniqness as the only allocated object.
    Board::~Board() { 
        delete board ;
    }

    //*Getter method which returns the farest row in the board which contains a value . 
    int Board::getRw() const{
        return maxRw;
    }
    
    //*Getter method which returns the farest column in the board which contains a value . 
    int Board::getCn() const{
        return maxCn;
    }

    //*Putts a string message inside the board, the starting charecter is at (row,column), the direction (horizontal/vertical) is determined by the Direction enum object.
    void Board::post(uint32_t row, uint32_t column, Direction direction, string message) {
        if(direction == horizontal){
            if(((int)row)>(maxRw)){
                (maxRw)=((int)row);
            }
            if(((int)column)+((int)message.length())>(maxCn)){
                (maxCn)=((int)column)+((int)message.length());
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
            if(((int)row)+((int)message.length())>(maxRw)){
                (maxRw)=((int)row)+((int)message.length());
            }
            if(((int)column)>(maxCn)){
                (maxCn)=((int)column);
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

    //*Returns a charecter which located on a specific location on the board, if the location is empty (uninitialized) the method returns an Underscore charecter .
    char Board::charAt(int row, int column){
        if((*board).find(row)!=(*board).end()){
            if((*board).at(row).find(column)!=(*board).at(row).end()){
                return ((*board).at(row).at(column));
            }
        }
        return '_';
    }   

    //*Returns a string of a specific length of a specific direction from a specific location.
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

    //*Prints the board using iterator.
    void Board::show() {
        for (const auto &row : *board){
            for (const auto &column : row.second){
                    cout << column.second;
            }
            cout << endl;
        }
    }
}



