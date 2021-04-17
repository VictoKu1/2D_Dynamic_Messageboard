#include "Board.hpp"
using namespace ariel;
using namespace std;
#include "Direction.hpp"
#include <fstream>
#include <cstdlib>
const Direction horizontal = Direction::Horizontal;
Board board = Board();
void extend(int row, int column, int inputLength)
{
    int rowTarget = row;
    int columnTarget = column + inputLength;
    int getCn = board.getCn();
    int getRw = board.getRw();
    if (rowTarget > getRw)
    {
        for (int i = getRw + 1; i <= rowTarget + 1; i++)
        {
            for (int j = 0; j <= getCn; j++)
            {
                board.post((uint32_t)i, (uint32_t)j, horizontal, " ");
            }
        }
    }
    if (columnTarget > getCn)
    {
        for (int i = 0; i <= rowTarget; i++)
        {
            for (int j = getCn + 1; j <= columnTarget + 1; j++)
            {
                board.post((uint32_t)i, (uint32_t)j, horizontal, " ");
            }
        }
    }
}
int main()
{
    int height = 0;
    int width = 0;
    for (height = 0; height < 1; height++)
    {
        for (width = 0; width < 7; width++)
        {
            board.post((uint32_t)height, (uint32_t)width, horizontal, " ");
        }
    }
    system("clear");
    cout << "Welcome to the text board.\n";
    string input;
    string status;
    cout << "Want to add something to the board ?\nY - for entering manually, \nP - for reading from a text file ,\nEvery other letter on the keyboard - for exiting.\n\n";
    for (;;)
    {
        if (cin >> status)
            break;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    if (status != "Y" && status != "P")
    {
        return 0;
    }
    for (;;)
    {
        int row;
        int column;
        system("clear");
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        system("clear");
        if (status == "Y")
        {
            cout << "Please enter what you wish to be shown on the board.\n";
            for (;;)
            {
                if (getline(cin, input))
                    break;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            system("clear");
            cout << "Enter the number of the row you wish to public you post.\n";
            cin >> row;
            cout << "Enter the number of the column you wish to public you post.\n";
            cin >> column;
            extend(row, column, input.length());
            board.post((uint32_t)row, (uint32_t)column, horizontal, input);
            system("clear");
            board.show();
        }
        else
        {
            cout << "List of files:\n";
            system("ls");
            cout << "\n\nEnter the name of a file you want to read from:\n";
            string address;
            cin >> address;
            string myText;
            ifstream MyReadFile(address);
            if (!MyReadFile)
            {
                string bashCom = "touch " + address;
                system(bashCom.c_str());
            }
            system("clear");
            cout << "Enter the number of the row you wish to public you post.\n";
            cin >> row;
            cout << "Enter the number of the column you wish to public you post.\n";
            cin >> column;
            while (getline(MyReadFile, myText))
            {
                extend(row, column, input.length());
                board.post((uint32_t)row, (uint32_t)column, horizontal, myText);
                row++;
            }
            MyReadFile.close();
            system("clear");
            board.show();
        }
        cout << "Want to add something more ?\n Y - for entering manually,\n P - for reading from a text file ,\n S - for saving ,\n Every other letter on the keyboard - for exiting. \n";
        for (;;)
        {
            if (cin >> status)
                break;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        if (status != "Y" && status != "P" && status != "S")
        {
            return 0;
        }
        if (status == "S")
        {
            system("clear");
            system("ls");
            cout << "\nEnter the name of a file you want to save to:\n\n";
            string address;
            cin >> address;
            ofstream sFile(address);
            if (!sFile.is_open())
            {
                string bashCom = "touch " + address;
                system(bashCom.c_str());
            }
            sFile.close();
            ofstream ofs;
            ofs.open(address, ofstream::out | ofstream::trunc); //*Cleans the file.
            ofs.close();
            system("clear");
            ofstream out(address);             //*Preparing to stream cout to given the text file.
            streambuf *coutbuf = cout.rdbuf(); //*Save old buffer.
            cout.rdbuf(out.rdbuf());           //*Redirect cout to the given text file address .
            board.show();
            cout.rdbuf(coutbuf); //*Redirect cout back to its default setting.
            cout << "Want to add something more ?\n Y - for entering manually,\n P - for reading from a text file ,\n Every other letter on the keyboard - for exiting.\n\n";
            for (;;)
            {
                if (cin >> status)
                    break;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            if (status != "Y" && status != "P")
            {
                return 0;
            }
        }
    }
    return 0;
}