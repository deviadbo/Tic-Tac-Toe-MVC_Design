#pragma once
#include "BoardGame.h"

enum Type { Row, Cell, Diag, revDiag };

class Line
{
public:
    Line() {}
    Line(Type type, int CSF, int PSF , int empty) : line_type(type), CompSlotFilled(CSF), PlayerSlotFilled(PSF), emptySlot(empty) {}
public:
    Type line_type;
    int CompSlotFilled = 0;         // Computer Count some full slots
    int PlayerSlotFilled = 0;       // Player Count some full slots
    Move emptySlot;
};

class TicTacToeGame :
    public BoardGame
{
    public:
        TicTacToeGame(char** board) : BoardGame(board) {};
        GameState getGameState();
        void updateGameState();
        virtual void getComputerMove() = 0;
        Result setPlayerMove(Move);
     protected:
         void RandomComputerMove();


    public:
        Line checkDiag();
        Line checkRevDiag();
        Line checkRow(int i);
        Line checkCell(int j);
};

