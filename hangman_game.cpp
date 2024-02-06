#include "hangman_game.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void createAndWriteWordsToFile(const string& filename) {
    ofstream file(filename);

    if (file.is_open()) {
        file << "programming" << endl;
        file << "hangman" << endl;
        file << "cplusplus" << endl;
        file << "computer" << endl;
        file << "science" << endl;
        file << "sport" << endl;
        file << "table" << endl;
        file << "good" << endl;

        file.close();
        cout << "Words have been written to the file." << endl;
    }
    else {
        cerr << "Error: Unable to create or open file '" << filename << "'." << endl;
        exit(EXIT_FAILURE);
    }
}

vector<string> readWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);

    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            words.push_back(word);
        }

        file.close();
        cout << "Loaded words from file." << endl;
    }
    else {
        cerr << "Error: Unable to open file '" << filename << "'." << endl;
        exit(EXIT_FAILURE);
    }

    return words;
}

void displayWord(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end() || !isalpha(letter)) {
            cout << letter << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void displayHangman(int attempts) {
    switch (attempts) {
    case 0:
        cout << " ____" << endl;
        cout << "|    |" << endl;
        cout << "|    " << endl;
        cout << "|    " << endl;
        cout << "|    " << endl;
        cout << "|_____" << endl;
        break;
    case 1:
        cout << " ____" << endl;
        cout << "|    |" << endl;
        cout << "|    O" << endl;
        cout << "|    " << endl;
        cout << "|    " << endl;
        cout << "|_____" << endl;
        break;
    case 2:
        cout << " ____" << endl;
        cout << "|    |" << endl;
        cout << "|    O" << endl;
        cout << "|    |" << endl;
        cout << "|    " << endl;
        cout << "|_____" << endl;
        break;
    case 3:
        cout << " ____" << endl;
        cout << "|    |" << endl;
        cout << "|    O" << endl;
        cout << "|   /|" << endl;
        cout << "|    " << endl;
        cout << "|_____" << endl;
        break;
    case 4:
        cout << " ____" << endl;
        cout << "|    |" << endl;
        cout << "|    O" << endl;
        cout << "|   /|\\" << endl;
        cout << "|    " << endl;
        cout << "|_____" << endl;
        break;
    case 5:
        cout << " ____" << endl;
        cout << "|    |" << endl;
        cout << "|    O" << endl;
        cout << "|   /|\\" << endl;
        cout << "|   / \\" << endl;
        cout << "|_____" << endl;
        break;
    case 6:
        cout << " ____" << endl;
        cout << "|    |" << endl;
        cout << "|    O" << endl;
        cout << "|   /|\\" << endl;
        cout << "|   / \\" << endl;
        cout << "|_____" << endl;
        break;

    default:
        break;
    }
}


