#include "Board.hpp"
using namespace ariel;
using namespace std;
#include "Direction.hpp"
// bool in(int output,int valid[]){
//     if(output>=valid[0]&&output<=valid[1]){
//         return true;
//     }
//     return false;
// }
// bool oneOfThem(int output,int valid[],int length){
//     for(int i=0;i<length;i++){
//         if(output==valid[i]){
//             return true;
//         }
//     }
//     return false;
// }
// int readAndCheck(string message,int valid[],int length,string selectiveOrange){
//     int output ;
//     for(;;){
//         if(cin >> output)
//             break;
//         cin.clear();
//         cin.ignore(INT_MAX,'\n');
//     }
//     if(selectiveOrange==range){
//         while(!in(output,valid)){
//             cout<<message<<endl;
//             for(;;){
//                 if(cin >> output)
//                     break;
//                 cin.clear();
//                 cin.ignore(INT_MAX,'\n');
//             }
//         }
//         return output ;
//     }
//     if(selectiveOrange==selective){
//         while(!oneOfThem(output,valid,length)){
//             cout<<message<<endl;
//             for(;;){
//                 if(cin >> output)
//                     break;
//                 cin.clear();
//                 cin.ignore(INT_MAX,'\n');
//             }
//         }
//         return output ;
//     }
//     throw invalid_argument{"Invalid direction ."};
// }
// void encode(){
//     system("clear");
//     cout<<"Let's encode something."<<endl;
// }
// void decode(){
//     system("clear");
//     cout<<"Let's decode something."<<endl;
// }
int main(){
    Board board=Board();
    system("clear") ;
    cout<<"Welcome to the text board."<<endl;
    string input ;
    string status = "Y";
    while(status=="Y"){
        cout<<"Please enter what you wish to be shown on the board."<<endl;
        cin>>input;
        system("clear") ;
        int row ;
        int column ;
        cout<<"Enter the number of the row you wish to public you post."<<endl;
        cin>>row;
        cout<<"Enter the number of the column you wish to public you post."<<endl;
        cin>>column;
        system("clear") ;
        const Direction horizontal = Direction::Horizontal;
        board.post((uint32_t)row,(uint32_t)column,horizontal,input);
        board.show();
        cout<<"Want to add something more (Y-for yes, <Everything else> for exiting)?"<<endl;
        cin>>status;
    }
    return 0;
//     cout<<"Welcome to the hash image encoder/decoder !"<<endl;
//     string message = "For encoding press 1,\n For decoding press 5 ,\n For safe exiting press 69. \n";
//     cout<<message;
//     int valid[]={1,5,69};
//     int choice = readAndCheck(message,valid,3,selective);
// choice:
//     if (choice==1){
//         encode();
//         system("clear");
//         message="Press:\n 1 - For encoding again.\n 5 - For decoding ,\n For safe exiting press 69.\n";
//         cout<<message;
//         choice = readAndCheck(message,valid,3,selective);
//         goto choice;
//     }
//     if(choice==2){
//         decode();
//         system("clear");
//         message="Press:\n 1 - For encoding .\n 5 - For decoding again,\n For safe exiting press 69.\n";
//         cout<<message;
//         choice = readAndCheck(message,valid,3,selective);
//         goto choice;
//     }
//     system("clear");
//     cout<<"Thank you for you time!\nBye ,\nHope to see you soon.\n";
//     return 0;
}
