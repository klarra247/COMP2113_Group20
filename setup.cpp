#include "setup.h"
#include "game.h"

using namespace std;

void printLine()
{
	cout<<"--------------------------------------------------"<<endl;
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
//this function saves the player's name and balance 

	ofstream fout;
	fout.open("players.txt");

	for(int i = 0; i < Players.size(); i++ )
	{
		fout << " " << Players[i].getName() << " " << Players[i].getWins() << endl;
	}
	fout.close();

}

//print the menu of game
void Game::intro()
{
	printLine();
	
	cout<<"1. Player registration : Enter P or p"<<endl;
	cout<<"2. Start game if you have registered your name : Enter S or s"<<endl;
	cout<<"3. To see Contributers : Enter C or c)"<<endl;
	cout<<"4. Exit game : E or e"<<endl;
	
	printLine();
	
    cout<<"Which menu do you want to choose? : ";
}

//startGame
void Game::startGame()
{
	/*
	 using member function from Blackjack class
	 */
}

// print the names of game contributors
void Game::contributors()
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


void Game::addPlayer()
{

    printLine();
    cout <<"Welcome, new player!"<<endl;
    string playerName;
    while(true)
	{
		try {
			cout << "Enter your name: ";
			cin >> playerName;
			cin.ignore();
			
			for(int i = 0; i < playerName.size(); i++)
			{
				if(isalnum(playerName[i]))
					continue;
				else
					throw playerName;
			}
			

            int j = getPlayerIndex(playerName);
            if (j != -1){
                cout << "Your name is already registered." << endl;
                break;
            }

            PlayerInfo newPlayer(1, playerName, 0);
            Players.push_back(newPlayer);
            return;

		}
		catch(...)
		{
			cout<<"Please Try Again"<<endl;
			cin.clear();
		}
	}

    
}
    
//to update player's information after every game
void Wordle::updatePlayer()
{
    int i = getPlayerIndex(currentPlayer.getName());
	Players[i].setPlayer(currentPlayer);
}

void Game::loadPlayers()
{
	ifstream fin;
	fin.open("players.txt");    

    if (!fin.is_open()) {
        cout << "Can not read file" <<endl;
    }

	string player_name;
	int player_wins;

    while (fin >>  player_name >> player_wins) {
        PlayerInfo existingPlayer(1, player_name, player_wins);
		Players.push_back(existingPlayer);
    } 
	
    if ( fin.is_open() ) {
        fin.close();
	}
}


// give the player his index number
int Game::getPlayerIndex(string playerName)
{
	int i = 0;
	int result = -1;

    while(i < Players.size())
    {
        if(Players[i].getName() == playerName)
        {
            result = i;
            break;
        }
        i++;
    }

	return result;
}




void Game::exit()
{
    savePlayers();
    cout << "Thank you for playing!" << endl;
}


Wordle::Wordle() : Game()
{}
Wordle::~Wordle()
{}

//load the player
bool Wordle::loadPlayer()
{
	string playerName;
    int j,k=-1;
	while(true)
	{
		try {
			cout<<"Enter your name : ";
			cin>>playerName;
			cin.ignore();
			if (playerName == "R" || playerName == "r"){
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

            j = getPlayerIndex(playerName);
			if( j == -1 )
			{
				cout<<endl<<"Your name does not exist. Enter R to register"<<endl;
				throw playerName;

			}
            k++;
			break;

		}
		catch (...)
		{
			cout << "Please Enter Again." << endl;
			cin.clear();
		}
	}
	currentPlayer.setPlayer(Players[j]);
	return true;

}

//ask to play another round
bool Wordle::restart()
{

    while(true)
    {
		cout<<"Do you want to play another round? (Y/N) : ";
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
			cout<<"Please Try Again."<<endl;
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


        if (restart()) {
            continue_game = true;
            cout << endl;
            cout << "Play Again" << endl;
            cout << endl;
        }

        else
            continue_game = false;
    }
    updatePlayer();
	
}



