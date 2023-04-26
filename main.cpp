#include <iostream>
#include <string>
#include <fstream>
//#include "spellcheck.h"
//#include "game.h"
#include "game_setup.h"
using namespace std;


void intro()
{
/*
prints the menu
output:lines printed
*/
	/*
	 1. To check the Information of the game
	 2. The user has to register his name before he begins playing the game
	 3. Start game is the player registered already
	 4. The user chooses to end the game
	 */

	cout<<"1. Who made this game?(I or i)"<<endl;
    cout << "\n" << endl;
	cout<<"2. Player registration (P or p)"<<endl;
	cout<<"3. Game start if you have entered your name.(S or s)"<<endl;
	cout<<"4. Exit game.(BYE or bye)"<<endl;

	cout<<"Which menu do you want to choose? : ";
}


int main(){

    string menu;
    intro();
    cin >> menu;
    cout << "---------------*--*--start playing W O R D L E--*--*---------------" << endl;
    cout << "\n" << endl;

    if (menu == "I" || menu == "i"){
        Contributors();
    }
    else if (menu == "P" || menu == "p"){
        Player();
    }
    else if (menu == "S" || menu == "s"){
        Start();
    }
    else if (menu == "BYE" || menu == "bye"){
        Exit();
        //break;
    }
    else{
        cout << endl;
        cout << "Please enter again" << endl;
        cout << endl;   
    }
    return 0;
}
    
    
    
