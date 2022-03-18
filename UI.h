#ifndef USER_INTERFACE
#define USER_INTERFACE
#include "setting.h"
#include "Move.h"
#include <iostream>
class UI
{
public:
    virtual void print(char** gameBoard) = 0;
    virtual Move getPlayerMove() = 0;
    virtual void printLine(const char*) = 0;
};

#endif
