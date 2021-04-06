#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"
using namespace std;
using namespace ariel;


int main() {
 	ariel::Board board;
    // declaration of all variables
    uint row , column , length;
    int func; // read is 2 , show is 3.
    int dir;
    string message;
    Direction direction;
    // wellcome line
     cout << "Wellcome to Assignment number two : "   << "\033[1;31mmessageboard part B\033[0m\n";
                         cout << "You can choose one of the option : "    << "\033[1;32mPost (Press 1)\033[0m "
                                                                          << "\033[1;33mRead (Press 2)\033[0m "
                                                                          << "\033[1;34mShow (Press 3)\033[0m "
                                                                          << "\033[1;35mExit (Press 4)\033[0m " << endl;
    cin >> func;
    while (func != 4) {
    switch(func) {
        //post function
        case 1:     cout << "\033[1;32mYou choose : Post\033[0m \n";
                    cout << "\033[1;32m1)\033[0m " << "for inserting a message horizontally please press 1 \n";
                    cout << "\033[1;32m2)\033[0m " << "for inserting a message vertically please press 2\n";
                    cin >> dir;
                     if(dir == 1 || dir == 2) { 
                         if (dir == 1) {direction = Horizontal;}
                         else if (dir == 2) {direction = Vertical;}
                          cout << "Please enter the position of the message by two indexes [i][j]\n";
                          cin >> row >> column;
                          cout << "\033[1;33mPlease enter the message \033[0m\n";
                          cin >> message;
                          board.post(row,column,direction,message);
                          cout << "\033[1;32mThe message was published successfully!\033[0m\n";
                          cout << "\nWellcome to Assignment number two : " << "\033[1;31mmessageboard part B\033[0m\n";
                          cout << "You can choose one of the option : "    << "\033[1;32mPost (Press 1)\033[0m "
                                                                           << "\033[1;33mRead (Press 2)\033[0m "
                                                                           << "\033[1;34mShow (Press 3)\033[0m "
                                                                           << "\033[1;35mExit (Press 4)\033[0m " << endl;
                         cin >> func;
                   }
                    else cout << "Wrong input , please try again. \n";

                    break;

        case 2:         cout << "\033[1;33mYou choose : Read\033[0m \n";
                        cout << "Please enter the position by two indexes [i][j]\n";
                        cin >> row >> column;
                        cout << "\033[1;32m1)\033[0m " << "for read the message horizontally please press 1 \n";
                        cout << "\033[1;32m2)\033[0m " << "for read the message vertically please press 2\n";
                        cin >> dir;
                        if(dir == 1 || dir == 2) { 
                        if (dir == 1) {direction = Horizontal;}
                        else if (dir == 2) {direction = Vertical;}
                        cout << "\033[1;32m2)\033[0m " << "Please enter the length of the reading\n";
                        cin >> length;
                        message = board.read(row,column,direction,length);
                        cout << "The message are : " << message << endl;
                        cout << "\nWellcome to Assignment number two : "   << "\033[1;31mmessageboard part B\033[0m\n";
                        cout << "You can choose one of the option : "      << "\033[1;32mPost (Press 1)\033[0m "
                                                                           << "\033[1;33mRead (Press 2)\033[0m "
                                                                           << "\033[1;34mShow (Press 3)\033[0m "
                                                                           << "\033[1;35mExit (Press 4)\033[0m " << endl;
                        
                        cin >> func;

                        }
                        else cout << "Wrong input , please try again. \n";
                        break;

        case 3:       cout << "\033[1;34mYou choose : Show\033[0m \n";
                      cout << "The message board is :\n";
                      board.show();
                      cout << "\nWellcome to Assignment number two : "     << "\033[1;31mmessageboard part B\033[0m\n";
                      cout << "You can choose one of the option : "        << "\033[1;32mPost (Press 1)\033[0m "
                                                                           << "\033[1;33mRead (Press 2)\033[0m "
                                                                           << "\033[1;34mShow (Press 3)\033[0m "
                                                                           << "\033[1;35mExit (Press 4)\033[0m " << endl;
                      cin >> func;
                      break;


        default: exit(1);
    }
}

}
