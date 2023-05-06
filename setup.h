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

void printLine();

class Game
{
protected:
	vector<PlayerInfo> Players; // registered player

public:
	Game();
	~Game();
	
	// Print intro on terminal
	void intro();

	// load player's index from players.txt
	int getPlayerIndex(string playerName);

	// Save player record on players.txt
	void savePlayers();

	// Load existing player
	void loadPlayers();
	
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
	
	// Update the player's information
	void updatePlayer();
};

#endif