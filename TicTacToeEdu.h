#pragma once
#include "TicTacToeGame.h"



class TicTacToeEdu :
    public TicTacToeGame
{
    public:
        TicTacToeEdu(char** board) : TicTacToeGame(board) {}
        void getComputerMove();


};

