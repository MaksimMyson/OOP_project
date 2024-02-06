#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include <vector>
#include <string>

void createAndWriteWordsToFile(const std::string& filename);

std::vector<std::string> readWordsFromFile(const std::string& filename);

void displayWord(const std::string& word, const std::vector<char>& guessedLetters);

void displayHangman(int attempts);

#endif // HANGMAN_GAME_H





