//
// Created by Dave R. Smith on 1/10/23.
//

#ifndef CS3A_SPRING2023_HANGMAN_FUNCTIONS_H
#define CS3A_SPRING2023_HANGMAN_FUNCTIONS_H
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

void getInput(char &letter);
char getInput();
std::string getDefaultBoard();
void drawBoard(const std::string& board);
void updateBoard(std::string& board, int misses);
bool inWord(const std::string& word, char letter);
void prompt(const std::string& message);
std::string getWord(const std::vector<std::string>& words);
void loadFromFile(const std::string& filename, std::vector<std::string>& words);
bool openFile(std::ofstream& out, const std::string& filename);
bool openFile(std::ifstream& in, const std::string& filename);
void addWord(const std::string& word, const std::string& filename,std::vector<std::string>& words);
void closeFile(std::ofstream& out);
void closeFile(std::ifstream& in);
void outputLetterbank(const std::vector<char>& letterbank);
void updateLetterbank(std::vector<char>& letterbank, char guess);
bool checkInVec(const std::vector<std::string>& words, const std::string& word);
void run();
void printWord(const std::string &word);
void updateWord(const std::string &word, std::string& displayWord, char guess);
std::string getDisplayWord(const std::string &word);
bool gameOver(std::string displayWord, int misses);
std::string getStartImage();
std::string gameEndScreen();
std::string winnerWinner();
#endif //CS3A_SPRING2023_HANGMAN_FUNCTIONS_H
