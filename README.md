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

## Game instructions :
1. A 5-letter word is randomly chosen and taken from the file where words are stored (wordfile.txt).
2. User is asked to input any "valid 5-letter word" (by valid it means any 5-letter word that exists; stored in the file dictionary.txt). 
3. If the input word does not exist in dictionary.txt, the program asks the user to input another word.
4. If the user has input a valid 5-letter word, the program prints out the user input word in a 5-letter grid. 
5. If a letter in the grid exists in the correct word but in a different location, that letter is printed as yellow on the grid.
6. If a letter in the grid exists in the correct word and is in the same location, that letter is printed as grin on the grid.
7. If the user uses all 5 guesses and still answers wrong, the program prints "You failed to find the world" and asks if the user would continue or stop. 
8. If the user guesses the correct word, the program prints "Found the word" and asks if the user would play another round. 
9. If the user decides to play another round, the program prints "Play Again".
10. If not, the program asks user to choose from the menu. 

## Compilation and execution instructions :
