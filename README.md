# Wordle Game
## Team members :
Lee Sihyeon 3035834838

Lim Sohui 3035946162

Kum Sangyoon 3035859084

## Code requirements :
1. Generation of random game sets or events
    - The game randomly generates a number from 1 to 100 to choose a random word from the file of word list

2. Data structures for storing game status
    - The game saves and updates the player guess information after every guess.
    - (...) are used as data structures to store the game status
    
3. Dynamic memory management
    - Iterators and pointers are used for dynamic memory management.
    
4. File input/output (e.g., for loading/saving game status)
    - The directory has file "wordlist.txt" to save the 5-letter words
    - The fstream library is used to open file and get random words, and update used words.

5. Program codes in multiple files
    - game.cpp, game.h for game playing functions
    - spellcheck.cpp, spellcheck.game for spelling check functions
    - main.cpp for main function
    - Makefile for making main, and cleaning the directory
    
6. Proper indentation and naming styles & In-code documentation
    - Every functions, variables, structures are named relevantly to their purpose and the code has proper indentation.


## Implemented features :

## How to start game :
1. There are four menu to choose from:
    i. Player registration
    ii. Start game (if registered)
    iii. To see contributors
    iv. Exit game

2. The user must choose menu i, to register his/her name.

3. After registration, the user can press menu ii, enter his/her name and start the game.

## Game instructions :
1. A 5-letter word is randomly chosen and taken from the file where words are stored (wordfile.txt).

2. User guesses this word by entering any "valid 5-letter word" (by valid it means any 5-letter word that exists; stored in the file dictionary.txt). 

3. If user input is not a valid word, the user is asked to input a valid word.

4. If the user input is a valid 5-letter word, the program prints out the user input word onto a 5-letter grid.      
        4a. If a letter on the grid exists in the correct word but in a different location, that letter is printed as yellow on the grid.
        4b. If a letter on the grid exists in the correct word and is in the same location, that letter is printed as green on the grid.
            4b.i. If user guesses the correct word, all letters on the grid are shown green and the program prints out "Found the word"
            
5. If the user uses all 5 guesses and still answers wrong, the program prints "You failed to find the world".
 
6. If the user has guessed the word correctly or have failed to within all 5 guesses, the game is over --> user is asked if he/she wants to continue.

## Compilation and execution instructions :
1. Run the game by using makefile: makefile --> ./main
2. Clean the directory by using makefile: make clean
