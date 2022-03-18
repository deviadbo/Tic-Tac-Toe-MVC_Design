#pragma once
#include "GamesUI.h"
#include "Move.h"

class Console :
    public GamesUI
{
public:
    void print(char**);
    Move getPlayerMove();
    void printLine(const char*);

};
