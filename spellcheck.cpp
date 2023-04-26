#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

bool spellCheck(string s) {
    //open text file with all valid words
    string filename = "validwords.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error" << endl;
        return false;
    }

    //add every word from txt file to vector
    vector<string> words;
    string word;
    while (getline(file, word)) {
        words.push_back(word);
    }
    file.close();

    //binary search to see if word is valid 
    int lower = 0;
    int upper = words.size() - 1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        if (words[mid] == s) {
            return true;
        } else if(words[mid] < s) {
            lower = mid + 1;
        } else if(words[mid] > s) {
            upper = mid - 1;
        }
    }
    return false;
}

int main() {
    string word;
    cin >> word;

    if (spellCheck(word)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
