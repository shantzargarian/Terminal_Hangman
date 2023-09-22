//
// Created by Dave R. Smith on 1/17/23.
//
#include "tests.h"
void testBoard()
{
    std::string board;

    board = getDefaultBoard();

    for (int i = 0; i < 6; ++i)
    {
        updateBoard(board, i);
        std::cout << board << std::endl;

    }
}