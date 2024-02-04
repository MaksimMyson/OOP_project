#include "hangman_game.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cout << "Welcome to the Hangman Game!" << endl << endl;

    createAndWriteWordsToFile("words.txt");
    vector<string> words = readWordsFromFile("words.txt");
    string secretWord = words[0];

    const int maxAttempts = 6;
    vector<char> guessedLetters;

    time_t startTime = time(nullptr);

    int attempts = 0;
    while (attempts < maxAttempts) {
        cout << "Attempt " << attempts + 1 << "/" << maxAttempts << endl;
        displayHangman(attempts);
        displayWord(secretWord, guessedLetters);

        cout << "Enter a letter: ";
        string guess;
        cin >> guess;

        if (guess.length() == 1 && isalpha(guess[0])) {
            guessedLetters.push_back(tolower(guess[0]));
        }
        else {
            cout << "Invalid input. Please enter a single letter." << endl;
            continue;
        }

        if (secretWord.find(tolower(guess[0])) != string::npos) {
            cout << "Correct! The letter '" << tolower(guess[0]) << "' is in the word." << endl;
        }
        else {
            cout << "Incorrect. This letter is not in the word." << endl;
            attempts++;
        }

        if (all_of(secretWord.begin(), secretWord.end(), [&](char letter) {
            return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
            })) {
            cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
            break;
        }
    }

    time_t endTime = time(nullptr);
    int elapsedTime = static_cast<int>(endTime - startTime);

    cout << "\nGame Statistics:" << endl;
    cout << "Elapsed Time: " << elapsedTime << " seconds" << endl;
    cout << "Number of Attempts: " << attempts << endl;
    cout << "Secret Word: " << secretWord << endl;
    cout << "Player's Letters: ";
    for (char letter : guessedLetters) {
        cout << letter << " ";
    }
    cout << endl;

    cout << "Exiting program." << endl;

    return 0;
}