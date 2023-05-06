#ifndef SETUP_H
#define SETUP_H

#include "game.h"
#include "players.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void Lines(); //declares the function Lines 

class Game //class for Game and states its essential functions
{
protected:
	vector<PlayerInfo> Players; // registered player

public:
	Game();
	~Game();
	
	// Print intro on terminal
	void intro();

	// load player's index from players.txt
	int indexNum(string playerName);

	// Save player record on players.txt
	void savePlayers();

	// get player's index from players.txt
	int indexNum(string playerName);

	// Load existing player
	void loadPlayers();

	// Update player information
	void updatePlayer(string playerName);

    // Input user's name
    void addPlayer();
	
	// Start game
	virtual void startGame();

	// Print contributors of game
	void contributors();

	// Exit game
	void exit();





};

class Wordle : public Game
{
protected:

	GamePlayer currentPlayer; // current player (User)

public:
	Wordle();
	~Wordle();

	// Load the current player info : return true if no error, else return false
	bool loadPlayer();
	
	bool restart();

	virtual void startGame();

	void showRank();
	
	// Update the player's information
	void updatePlayer();
};




#endif
