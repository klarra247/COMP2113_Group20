#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib> // for the rand(), srand() functions to generate random numbers

using namespace std;



void checkCase(string& word) {
    for (int i = 0; i < word.length(); i++) {
        if(isupper(word[i])) {
            word[i] = tolower(word[i]);
        } 
    }
}

int playGame(string word) {
    string input;
    int count = 0;
    while (count < 5) {
        cout << "Enter a 5-letter word: ";
        cin >> input;
        if (input.length() != 5) {
            cout << "Invalid input. Please enter a 5-letter word." << endl;
            continue;
        }
        string correct = "";
        string wrong = "";
        string other = "";
        for (int i = 0; i < 5; i++) {
            if (input[i] == word[i]) {
                correct += input[i];
            }
            else if (word.find(input[i],0) != string::npos) {
                wrong += input[i];
            }
            else {
                other += input[i];
            }
        }

if (correct == input) {
            cout << "Congratulations! You guessed the correct word!" << endl;
            break;
        }
        else {
            count++;
            cout << "Incorrect guess. You have " << 5 - count << " guesses left." << endl;

        cout << "Letters that are in the word and in the correct spot: " << correct << endl;
        cout << "Letters that are in the word but in the wrong spot: " << wrong << endl;
        cout << "All other alphabets: " << other << endl;

            if (count == 5) {
                cout << "Sorry, you have used up all your guesses." << endl;
                break;
            }
        }


        
    }
    return 0;
}

int main(){
    playGame("hello");
    return 0;
}
