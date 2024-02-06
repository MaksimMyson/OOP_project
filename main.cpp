#include "hangman_game.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    cout << "Welcome to the Hangman Game!" << endl << endl;

    createAndWriteWordsToFile("words.txt");
    vector<string> words = readWordsFromFile("words.txt");

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Select a random word from the vector
    string secretWord = words[rand() % words.size()];

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

        // Check if the input is a single letter
        if (guess.length() == 1 && isalpha(guess[0])) {
            char guessedLetter = tolower(guess[0]);
            guessedLetters.push_back(guessedLetter);

            // Check if the guessed letter is in the secret word
            if (secretWord.find(guessedLetter) != string::npos) {
                cout << "Correct! The letter '" << guessedLetter << "' is in the word." << endl;
            }
            else {
                cout << "Incorrect. This letter is not in the word." << endl;
                attempts++;
            }

            // Check if all letters of the secret word have been guessed
            if (all_of(secretWord.begin(), secretWord.end(), [&](char letter) {
                return find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
                })) {
                cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
                break;
            }
        }
        else {
            cout << "Invalid input. Please enter a single letter." << endl;
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
