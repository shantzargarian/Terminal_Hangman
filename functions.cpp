//
// Created by Dave R. Smith on 1/10/23.
//
#include "functions.h"
#include <iostream>

std::string getStartImage()
{
    std::string starterBoard = "  _   _          _           _   _           ____        __  __          _           _   _     \n"
                " |'| |'|     U  /\"\\  u      | \\ |\"|       U /\"___|u    U|' \\/ '|u    U  /\"\\  u      | \\ |\"|    \n"
                "/| |_| |\\     \\/ _ \\/      <|  \\| |>      \\| |  _ /    \\| |\\/| |/     \\/ _ \\/      <|  \\| |>   \n"
                "U|  _  |u     / ___ \\      U| |\\  |u       | |_| |      | |  | |      / ___ \\      U| |\\  |u   \n"
                " |_| |_|     /_/   \\_\\      |_| \\_|         \\____|      |_|  |_|     /_/   \\_\\      |_| \\_|    \n"
                " //   \\\\      \\\\    >>      ||   \\\\,-.      _)(|_      <<,-,,-.       \\\\    >>      ||   \\\\,-. \n"
                "(_\") (\"_)    (__)  (__)     (_\")  (_/      (__)__)      (./  \\.)     (__)  (__)     (_\")  (_/\n"
                "                                                                                                       \n"
                "  _   _                 __  __                     ____  _                           \n"
                " | | | | _____      __ |  \\/  | __ _ _ __  _   _  |  _ \\| | __ _ _   _  ___ _ __ ___ \n"
                " | |_| |/ _ \\ \\ /\\ / / | |\\/| |/ _` | '_ \\| | | | | |_) | |/ _` | | | |/ _ \\ '__/ __|\n"
                " |  _  | (_) \\ V  V /  | |  | | (_| | | | | |_| | |  __/| | (_| | |_| |  __/ |  \\__ \\\n"
                " |_| |_|\\___/ \\_/\\_/   |_|  |_|\\__,_|_| |_|\\__, | |_|   |_|\\__,_|\\__, |\\___|_|  |___/\n"
                "                                           |___/                 |___/          \n";

    return starterBoard;
}

std::string gameEndScreen()
{
    std::string gameEnd = "   ____                         ___                 _ \n"
                          "  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __| |\n"
                          " | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__| |\n"
                          " | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |  |_|\n"
                          "  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|  (_)\n";

    return gameEnd;
}

std::string winnerWinner()
{
    std::string byeBye =  " __        ___                       _ \n"
                          " \\ \\      / (_)_ __  _ __   ___ _ __| |\n"
                          "  \\ \\ /\\ / /| | '_ \\| '_ \\ / _ \\ '__| |\n"
                          "   \\ V  V / | | | | | | | |  __/ |  |_|\n"
                          "    \\_/\\_/  |_|_| |_|_| |_|\\___|_|  (_)\n"
                          "                                       \n";
    return byeBye;
}

std::string getDefaultBoard()
{
    std::string board = "  +---+\n"
                        "  |   |\n"
                        "      |\n"
                        "      |\n"
                        "      |\n"
                        "      |\n"
                        "=========";
    return board;
}

void getInput(char &letter)
{
    std::cin >> letter;
}

char getInput()
{
    char letter;
    getInput(letter);
    return letter;
}

void drawBoard(const std::string& board)
{
    std::cout << board << std::endl;
}

void updateBoard(std::string& board, int misses)
{
    switch(misses)
    {
        case 1:
            board[18] = 'O';
        break;
        case 2:
            board[26] = '|';
        break;
        case 3:
            board[25] = '/';
        break;
        case 4:
            board[27] = '\\';
        break;
        case 5:
            board[33] = '/';
        break;
        case 6:
            board[35] = '\\';
        break;

    };
}

bool inWord(const std::string &word, char letter)
{
    return (word.find(letter) != std::string::npos);
}

void prompt(const std::string &message)
{
    std::cout << message;
}

std::string getWord(const std::vector<std::string> &words)
{
    return words.at(rand() % words.size());
}

void loadFromFile(const std::string &filename, std::vector<std::string> &words)
{
    std::ifstream fin;
    std::string next;
    if(openFile(fin, filename))
    {
        while(getline(fin,next))
            words.push_back(next);
    }
    closeFile(fin);
}

bool openFile(std::ofstream &out, const std::string &filename)
{
    out.open(filename);
    return !out.fail();
}

bool openFile(std::ifstream &in, const std::string &filename)
{
    in.open(filename);
    return !in.fail();
}

void addWord(const std::string &word, const std::string &filename, std::vector<std::string> &words)
{
    std::ofstream fout;
    if(openFile(fout,filename))
    {
        if(!checkInVec(words,word))
        {
            fout<<word<<std::endl;
            words.push_back(word);
        }
    }
    closeFile(fout);
}
bool checkInVec(const std::vector<std::string>& words, const std::string& word)
{
    for (int i = 0; i < words.size(); ++i)
    {
        if (words[i] == word)
            return true;
    }
    return false;
}


void closeFile(std::ofstream &out)
{
    out.close();
}

void closeFile(std::ifstream &in)
{
    in.close();
}

void outputLetterbank(const std::vector<char> &letterbank)
{
    for (int i = 0; i < letterbank.size(); ++i)
    {
        std::cout << letterbank[i] << " ";
    }
    std::cout << std::endl; //;)
}

void updateLetterbank(std::vector<char> &letterbank, char guess)
{
    letterbank.push_back(guess);
}

void printWord(const std::string &word)
{
    std::cout << word << std::endl;
}

void updateWord(const std::string &word, std::string& displayWord, char guess)
{

    if(inWord(word, guess))
    {
        for (int i = 0; i < word.size(); ++i)
        {
            if(word[i] == guess)
            {
                displayWord[i] =  guess;
            }
        }
    }
}

std::string getDisplayWord(const std::string &word)
{
    return std::string (word.length(), '_');
}

bool gameOver(std::string displayWord, int misses)
{
    return (displayWord.find('_') == std::string::npos || misses == 6);
}

void run()
{
    std::vector<int> misses;
    std::vector<std::string> wordBank;
    std::vector<std::vector<char>> letterBanks;
    std::vector<char> defaultBank;
    std::vector<std::string> playerWords;
    std::vector<std::string> displayWords;
    std::vector<std::string> boards;
    std::vector<bool> gameLoss;
    std::string youLose, tahDah, starterBoard;
    int numPlayers;

    tahDah = winnerWinner();
    youLose = gameEndScreen();
    starterBoard = getStartImage();

    std::cout<< starterBoard;
    std::cin >> numPlayers;

    loadFromFile("words.txt", wordBank);
    srand(time(nullptr));
    for(int i = 0; i < numPlayers; i++)
    {
        playerWords.push_back(getWord(wordBank));
        boards.push_back(getDefaultBoard());
        letterBanks.push_back(defaultBank);
        misses.push_back(0);
        gameLoss.push_back(false);
    }
    for(int i = 0; i < numPlayers; i++)
    {
        displayWords.push_back(getDisplayWord(playerWords[i]));
    }
    bool everyoneLost = false;
    bool gameWinInstance = false;
    int winPlayer = 0;
    while(!gameWinInstance && !everyoneLost)
    {
        std::cin.clear();
        for(int playerCount = 1; playerCount < numPlayers+1; playerCount++)
        {
            int i = 0;
            for(std::string displayWord : displayWords)
            {
                if(gameOver(displayWord, misses[i]))
                {
                    if(misses[i] >= 6)
                    {
                        gameLoss[i] = true;
                    }
                    else{
                        gameWinInstance = true;
                        winPlayer = i+1;
                        break;
                    }
                }
                i++;
            }
            for(bool loss : gameLoss)
            {
                if(loss)
                {
                    everyoneLost = true;
                }
                else
                {
                    everyoneLost = false;
                    break;
                }
            }
            if(gameWinInstance || everyoneLost){
                break;
            }
            if(!gameLoss[playerCount-1])
            {
                std::cout << "Player " << playerCount << "'s turn " << std::endl;
                std::cin.clear();
                int check = misses[playerCount-1];
                while(check == misses[playerCount-1] && !gameOver(displayWords[playerCount-1], misses[playerCount-1]))
                {
                    drawBoard(boards[playerCount-1]);
                    updateWord(playerWords[playerCount-1], displayWords[playerCount-1], ' ');
                    prompt(displayWords[playerCount-1]);

                    std::cout<<std::endl;
                    outputLetterbank(letterBanks[playerCount-1]);
                    prompt("Please enter your guess ");
                    char input;
                    getInput(input);
                    input = (char) tolower(input);
                    if(!inWord(playerWords[playerCount-1], input))
                    {
                        misses[playerCount-1]++;
                        std::cout << "incorrect guess " << std::endl;
                        updateBoard(boards[playerCount-1], misses[playerCount-1]);
                    }
                    else
                    {
                        updateWord(playerWords[playerCount-1], displayWords[playerCount-1], input);
                    }
                    updateLetterbank(letterBanks[playerCount-1], input);
                }
            }
            else
            {
                std::cout << "Player " << playerCount << " has lost, proceeding to Player " << playerCount+1 << "...." << std::endl;
            }
        }
    }
    std::cout << "\n\n The game has ended. " << std::endl;
    if(winPlayer != 0)
    {
        std::cout << "The Winner is: Player " << winPlayer << std::endl;
        std::cout <<tahDah;
    }
    else
    {
        drawBoard(boards[0]);
        std::cout << "All players have lost the game." << std::endl;
        std::cout << youLose;
    }
}