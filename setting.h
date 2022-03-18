#pragma once
using namespace std;

enum Result { Success, WrongMove };
enum GameState { ComputerWin, inGame, PlayerWin, Tie };

#define EDU 1
#define RAND 2
#define BORAD_SIZE 3

#include "Move.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
