# Wordle Game
## Team members :
Lee Sihyeon 3035834838

Lim Sohui 3035946162

Kum Sangyoon 3035859084

## Code requirements :
1. Generation of random game sets or events
    - The game randomly choose a word to be guessed from the file of word list

2. Data structures for storing game status
    - The game saves and updates the player name and the number of wins after each round of game.
    - Classes, this -> pointers, and vectors are used as data structures to save the game status

3. Dynamic memory management
    - Iterators and pointers are used for dynamic memory management.
    - The game uses functions to output the ranks of each players. Dynamic memory management is used when going through the number of wins of all existing players. 
    
4. File input/output (e.g., for loading/saving game status)
    - The directory has file "wordlist.txt" to save the 5-letter words (answer)
    - The directory has file "dictionary.txt" to save all 5-letter words 
    - The directory contains "players.txt" file to save the players.
    - The fstream library is used to open file and get random words, dictionary words,  and update player information (name, number of winnings).

5. Program codes in multiple files
    - game.cpp, game.h for game playing functions
    - setup.cpp, setup.h for game environment setup related functions
    - player.cpp, player.h for player information related functions
    - main.cpp for main function
    - Makefile for making main, and cleaning the directory
    
6. Proper indentation and naming styles & In-code documentation
    - Every functions, variables, structures are named relevantly to their purpose and the code has proper indentation.


## Implemented features :
- Classes(public, protected, private) for storing the player information
- Vector used to store items of different types 
- Various types of functions(void, int, bool) for running the game
- Exceptions(try, catch, throw) for dynamic work flow

## How to start game :
1. There are four menu to choose from:
    1. Player registration
    2. Start game (if registered)
    3. To see contributors
    4. Exit game

2. The user must choose menu (i), to register his/her name.

3. After registration, the user can press menu (ii), enter his/her name and start the game.

## Game instructions :
1. A 5-letter word is randomly chosen and taken from the file where words are stored (wordfile.txt).

2. User guesses this word by entering any "valid 5-letter word" (by valid it means any 5-letter word that exists; stored in the file dictionary.txt). 

3. If user input is not a valid word, the user is asked to input a valid word.

4. If the user input is a valid 5-letter word, the program prints out the user input word onto a 5-letter grid.      
    1. If a letter on the grid exists in the correct word but in a different location, that letter is printed as yellow on the grid.
    2. If a letter on the grid exists in the correct word and is in the same location, that letter is printed as green on the grid.
        1. If user guesses the correct word, all letters on the grid are shown green and the program prints out "Found the word"
            
5. If the user uses all 5 guesses and still answers wrong, the program prints "You failed to find the word".
 
6. If the user has guessed the word correctly or have failed to within all 5 guesses, the game is over

7. The player's name, number of wins, and rank is displayed --> user is asked if he/she wants to continue.

## Compilation and execution instructions :
1. Compile the game by using makefile: make main
2. Run the game: ./main
3. Clean the directory by using makefile: make clean

