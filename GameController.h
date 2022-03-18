#include "UI.h"
#include "Game.h"
#include "setting.h"

#pragma once
class GameController
{
public:
    GameController(UI* ui, Game* g) : ui(ui), game(g) {}
    void Play();
 private:
    Game* game;
    UI* ui;
};
