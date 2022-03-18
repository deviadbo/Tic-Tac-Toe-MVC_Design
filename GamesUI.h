#pragma once
#include "UI.h"
class GamesUI : public UI
{
public:
    virtual void print(char** gameBoard) = 0;
    virtual Move getPlayerMove() = 0;
    virtual void printLine(const char*) = 0;
};

