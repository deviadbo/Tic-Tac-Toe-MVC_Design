#pragma once
#include "setting.h"
class Game
//Interface
{
    public:
        virtual Result setPlayerMove(Move move) = 0;
        virtual void getComputerMove() = 0;
        virtual GameState getGameState() = 0;
        virtual void updateGameState() = 0;
        virtual  char** getGameBase() = 0;
};

