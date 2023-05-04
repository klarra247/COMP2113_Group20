#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PlayerInfo 	//class for PlayerInfo
{

protected:
    int player_id = 1;		//player_id initilized to 1
    string player_name;		//variable for name of the player
    int player_wins = 0;               //variable for the player's wins


public:     // Initializing Player
	
//class PlayerInfo initilization with player id, player name, and player guesses as input
    PlayerInfo(int player_id, string player_name, int player_wins);	
//class PlayerInfo initilization
    PlayerInfo();
//class PlayerInfo destructor
    ~PlayerInfo();

public:
    // Setting Information
    void setName(PlayerInfo player);		//Sets the name of the player
    void setPlayer (PlayerInfo player);	//Sets the id of player
    void setWins(int wins);	//Sets the wins of player

    int getId() const;				//Getting the player's id
    string getName() const;			//Getting the name of the player
    int getWins() const;			//Getting the player's wins
//    inline string getName() const {return player_name;}
//    inline int getGuesses() const {return player_guesses;}
};

// Inheritance of PlayerInfo class to GamePlayer Class
class GamePlayer : public PlayerInfo		
        
{

public:
    // Initilization
    //class GamePlayer initilization with player id, player name, and player guesses as input 
    GamePlayer(int player_id, string player_name, int wins);		
    //class GamePlayer initilization
    GamePlayer();
    //class GamePlayer destructor
    ~GamePlayer();

public:		
    //Setting Player in-game Information
    void show_info();						//shows the player's information

    void getWins();				//getting the guesses the player has made

};
