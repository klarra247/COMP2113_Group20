
#include <iostream>
#include <string>
#include <cctype>
#include "game.h"
#include "setup.h"
#include "players.h"
using namespace std;

int main(){
    Wordle WD;
    string input;

    cout << "====================================================================" <<  endl;
    cout << "|                                                                  |" <<  endl;
    cout << "|   WW\\      WW\\                           DD\\ LL\\                 |" <<  endl;
    cout << "|   WW | W\\  WW |                          DD |LL |                |" <<  endl;
    cout << "|   WW |WWW\\ WW | OOOOOO\\   RRRRRR\\   DDDDDDD |LL | EEEEEE\\        |" <<  endl;
    cout << "|   WW WW WW\\WW |OO  __OO\\ RR  __RR\\ DD  __DD |LL |EE  __EE\\       |" <<  endl;
    cout << "|   WWWW  _WWWW |OO /  OO |RR |  \\__|DD /  DD |LL |EEEEEEEE |      |" <<  endl;
    cout << "|   WWW  / \\WWW |OO |  OO |RR |      DD|   DD |LL |EE   ____|      |" <<  endl;
    cout << "|   WW  /   \\WW |\\OOOOOO  |RR |      \\DDDDDDD |LL |\\EEEEEEE\\       |" <<  endl;
    cout << "|  \\__/      \\__| \\______/ \\__|       \\_______|\\__| \\_______|      |" <<  endl;
    cout << "|                                                                  |" <<  endl;
    cout << "====================================================================" <<  endl;

    cout << "-----------------*--*--WELCOME TO W O R D L E--*--*-----------------" << endl;    
    cout << endl;

while(1)
    {
        WD.intro();

            cin >> input;
            cin.ignore();

            if (input == "P" ||  input == "p") 
            {
                WD.addPlayer();
            }
            else if ( input == "S" ||  input == "s") 
            {
                
                WD.startGame();
            }
            else if ( input == "C" ||  input == "c") 
            {
                WD.contributors();
            }
            else if ( input == "E" ||  input == "e") 
            {
                WD.exit();
                break;
            }
            else
            {
                cout << endl;
                cout << "Please enter again." << endl;
                cout << endl;
                cin.clear();
            }
        }
    return 0;
}
