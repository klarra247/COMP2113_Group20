#include "players.h"


using namespace std;

PlayerInfo::PlayerInfo(int player_id, string player_name, int player_wins) :player_id(player_id), player_name(player_name), player_wins(player_wins)
{}			//class initilization where input is player id, name of player, and number of wins of player

PlayerInfo::PlayerInfo() {} 	//class initilization with no specific input
PlayerInfo::~PlayerInfo() {}	//class destructor


//sets the player's basic information of id, name, and wins of players
//and output is storing the player's information onto class variables.
void PlayerInfo::setPlayer(PlayerInfo player)		
{
    this->player_id = player.player_id;
	this->player_name = player.player_name;
    this->player_wins = player.player_wins;
}

//displays the player's name and number of wins. 
void GamePlayer::show_info()
{
	cout<<"Player Name : " <<this->player_name<<endl;
	cout<<"Current Wins : "<< this->player_wins<<endl;

}

//returns the information of player's id
int PlayerInfo::getId() const
{
	return player_id;
}

//returns the name of the player
string PlayerInfo::getName() const
{
    return  player_name;
}


//sets the player's wins and stores it by getting the input of number of wins
void PlayerInfo::setWins()
{
    // cin >> player_balance;
    player_wins += 1;
}

//returns the wins of the player
int PlayerInfo::getWins() const
{
    return  player_wins;
}

//class initilization for Game player with inheritance of playerInfo. Given input is player id and player name 
GamePlayer::GamePlayer(int player_id, string player_name, int wins)
{
    PlayerInfo(player_id, player_name, wins);		//As GamePlayer under goes initilization, the inheritance class of PlayerInfo is 
									                            //also initilized.
}

//GamePlayer class initilization. As GamePlayer is initilized, PlayerInfo class is also initilized
GamePlayer::GamePlayer() : PlayerInfo()					
{}

//class GamePlayer destructor
GamePlayer::~GamePlayer()
{}




