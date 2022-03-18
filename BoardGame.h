#pragma once
#include "Game.h"
class BoardGame :
    public Game
{
    public:
        BoardGame(char** board) : m_board(board) {}
        virtual void getComputerMove() = 0;
        virtual Result setPlayerMove(Move) = 0;
        char** getGameBase() { return m_board; };
    protected:    // on the pdf its private
        char** m_board;
        GameState m_state;
};

