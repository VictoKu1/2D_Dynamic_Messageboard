#include "Board.hpp"
using namespace ariel;
using namespace std;
#include "Direction.hpp"
const Direction horizontal = Direction::Horizontal;
Board board=Board();
void extend(int row ,int column,int inputLength){
    int rowTarget=row;
    int columnTarget=column+inputLength;
    int getCn = board.getCn();
    int getRw = board.getRw();
    if(rowTarget > getRw){
        for(int i=getRw+1;i<=rowTarget+1;i++){
            for(int j=0;j<=getCn;j++){
                board.post((uint32_t)i,(uint32_t)j,horizontal," ");

            }
        }
    }
    if(columnTarget > getCn){
        for(int i=0;i<=rowTarget;i++){
            for(int j=getCn+1;j<=columnTarget+1;j++){
                board.post((uint32_t)i,(uint32_t)j,horizontal," ");
            }
        }
    }
}
int main(){
    int height=0;
    int width=0;
    for(height=0;height<1;height++){
        for(width=0;width<7;width++){
                board.post((uint32_t)height,(uint32_t)width,horizontal," ");
        }
    }
    system("clear") ;
    cout<<"Welcome to the text board.\n";
    cout<<"Please press ENTER to continue.\n";
    string input ;
    for(;;){
        string status;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        system("clear") ;
        cout<<"Please enter what you wish to be shown on the board.\n";
        for(;;){   
            if(getline(cin, input))
                break;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        system("clear") ;
        int row ;
        int column ;
        cout<<"Enter the number of the row you wish to public you post.\n";
        cin>>row;
        cout<<"Enter the number of the column you wish to public you post.\n";
        cin>>column;
        system("clear") ;
        extend(row,column,input.length());
        board.post((uint32_t)row,(uint32_t)column,horizontal,input);
        board.show();
        cout<<"\nWant to add something more ?\n(Y-for yes, <Everything else> for exiting)\n";
        for(;;){
            if(cin >> status)
                break;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        if(status!="Y"){
            return 0;
        }
    }
    return 0;
}