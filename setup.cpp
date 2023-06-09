#include "setup.h"
#include "game.h"

using namespace std;

void Lines() //creating a line that separates each menu box
{
	cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
}


Game::Game() {}

Game::~Game()
{
    // when game is over, save the player's name and correct answers in "players.txt"
	savePlayers();
}


// to save player's name and nubmer of wins
void Game::savePlayers()
{
	ofstream fout;
	fout.open("players.txt");

	for(int i = 0; i < Players.size(); i++ )
	{
		fout << Players[i].getId() << " " << Players[i].getName() << " " << Players[i].getWins() << endl;
	}
	fout.close();

}

//print the menu of game
void Game::intro()
{
	Lines();
	
	cout<<"1. Player sign-up : Enter P or p"<<endl;
	cout<<"2. Start game if you have already signed-up : Enter S or s"<<endl;
	cout<<"3. See game contributors : Enter C or c"<<endl;
	cout<<"4. Exit game : E or e"<<endl;
	
	Lines();
	
    cout<<"Please select a menu : ";
}

//startGame
void Game::startGame()
{
	
}

// print the names of game contributors
void Game::contributors()
{
    cout << "========================================="<<endl;
    cout << "||                                     ||"<<endl;
    cout << "||  These people have contributed...   ||"<<endl;
    cout << "||                                     ||"<<endl;
    cout << "||            Kum Sangyoon             ||"<<endl;
    cout << "||            Lee Sihyeon              ||"<<endl;
    cout << "||            Lim Sohui                ||"<<endl;
    cout << "||                                     ||"<<endl;
    cout << "========================================="<<endl;
}
    
//to update player's information after every game
void Wordle::updatePlayer()
{
    int i = indexNum(currentPlayer.getName());
	if (i == -1) {
		return;
	}
	Players[i].setPlayer(currentPlayer);
}

// to show the rank of the player after every game
void Wordle::showRank(){
    vector<PlayerInfo>::iterator i;
	int rank = Players.size();
	int id = indexNum(currentPlayer.getName());
	int wins = Players[id].getWins();
	int same = -1;
    for(i=Players.begin(); i != Players.end(); i++){
        if (wins >(*i).getWins())
		{
			rank -=1;
		}
		if (wins ==(*i).getWins()){
			same+=1;
		}
    }
    cout<<"Your Rank is : "<<rank - same << " out of " <<Players.size()<<endl;
	Lines();
}

void Game::addPlayer() //to register a new user into the game
{

    Lines();
    cout <<"Welcome, new player!"<<endl;
    string playerName;
    while(true)
	{
		try {
			cout << "Enter your name: ";
			cin >> playerName; 			//the user enters his or her name
			cin.ignore();
			
			for(int i = 0; i < playerName.length(); i++)
			{
				if(isalnum(playerName[i]))
					continue;
				else
					throw playerName;
			}
			

            int j = indexNum(playerName);  
            if (j != -1){
                cout << "Your name is already registered XD" << endl;   //if the name that user has entered already exists
                break;
            }

			
            PlayerInfo newPlayer(Players.size()+1, playerName, 0);
            Players.push_back(newPlayer);
            return;

		}
		catch(...)
		{
			cout<<"Please Try Again."<<endl;
			cin.clear();
		}
	}
}
    

//load the name of the registered players from the players.txt file
void Game::loadPlayers()
{
	ifstream fin;
	fin.open("players.txt");    

    if (!fin.is_open()) {
        cout << "Can not read file" <<endl;
    }

	string player_name;
	int player_id, player_wins;

    while (fin >> player_id >>player_name >> player_wins) {
        PlayerInfo existingPlayer(player_id, player_name, player_wins);
		Players.push_back(existingPlayer);
    } 
	
    if ( fin.is_open() ) {
        fin.close();
	}
}


//check whether or not the player has been registered already by providing an index number
int Game::indexNum(string playerName)
{
	for (int i = 0; i < Players.size(); i++) {
		if (Players[i].getName() == playerName) {
			return i;
		}
	}
	return -1;
}



//exit the game
void Game::exit()
{
    savePlayers();
    cout << "Thank you for playing! :)" << endl;
}


Wordle::Wordle() : Game()
{}
Wordle::~Wordle()
{}

//load the player
bool Wordle::loadPlayer()
{
	updatePlayer();
	string playerName;
    int num;
	while(true)
	{
		try {
			cout<<"Enter your name : ";		//asks the user to input his or her name to start the game
			cin>>playerName;
			cin.ignore();
			if (playerName == "R" || playerName == "r"){	//if the user inputs R or r for registration, the game asks the user for their user name
                addPlayer();
                break;
            }
			for(int i = 0; i < playerName.size(); i++)
			{
				if(isalnum(playerName[i]))
					continue;
				else
					throw playerName;
			}

        num = indexNum(playerName);
			if( num == -1 )
			{
				cout<<endl<<"Your name does not exist. Enter R to register"<<endl;
				throw playerName;

			}
		currentPlayer.setPlayer(Players[num]);
		return true;
		}
		catch (...)
		{
			cout << "Please Enter Again :<" << endl;
			cin.clear();
		}
	}
}

//ask to play another round
bool Wordle::restart()
{

    while(true)
    {
		cout<<"Are you up for another round? :) (Y or N) : ";
    	char answer;
        
			cin>>answer;
			cin.ignore();
			

			if(!isalpha(answer))
				throw answer;
			else{
                if (answer == 'Y' || answer == 'y')
                    return true;
                else if (answer == 'N' || answer == 'n')
                    return false;
            	else
		{
			cout<<"Please Try Again :("<<endl;
			cin.clear();
		}
    }

}
    return false;
}

//start game
void Wordle::startGame() {

    bool continue_game;
    if(loadPlayer())
    {
        continue_game = true;
    }
    else
    {
        continue_game = false;
    }

    while (continue_game) {


        if (playGame()){
			currentPlayer.setWins();

		};

		currentPlayer.show_info();

		showRank();


        if (restart()) {
            continue_game = true;
            cout << endl;
            cout << "Play Again :)" << endl;
            cout << endl;
        }

        else
            continue_game = false;
    }
    updatePlayer();
}



