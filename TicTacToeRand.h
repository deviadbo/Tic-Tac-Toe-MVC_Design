#pragma once
#include "TicTacToeGame.h"
class TicTacToeRand :
    public TicTacToeGame
{
    public:
        TicTacToeRand(char** board) : TicTacToeGame(board) {}
        void getComputerMove();
};

