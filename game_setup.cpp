
//#include "게임.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void Contributors()
{
    cout << "========================================="<<endl;
    cout << "||                                     ||"<<endl;
    cout << "||      Contributors of this game      ||"<<endl;
    cout << "||                                     ||"<<endl;
    cout << "||            Kum Sangyoon             ||"<<endl;
    cout << "||            Lee Sihyeon              ||"<<endl;
    cout << "||            Lim Sohui                ||"<<endl;
    cout << "||                                     ||"<<endl;
    cout << "========================================="<<endl;
}


void Player()
{
/*
adds playername by user's input
input:playername
output:if the name only includes alphabet and number, added to vector players, print "Please try again" otherwise.
*/
	/*
	 Enter name
	 */

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    
    ofstream fout("players_name.txt"); //유저네임 저장 음 할필요 없으려나..?
    fout << name;
    fout.close();

    cout << "Welcome "<< name << endl;
    
}
    


//startgame
void Start()
{
    /*
    // wrordle 게임 function 
	 using member function from wordle class
	*/
}



void Exit()
{
    //플레이어 기록 알려주기
    //savePlayers();
    cout << "Thank you for playing" << endl;
}



