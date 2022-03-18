#include <iostream>
using namespace std;

#include "Game.h"
#include "UI.h"
#include "GameController.h"

#include "TicTacToeRand.h"
#include "TicTacToeEdu.h"
#include "Console.h"

int main()
{
    cout << "Welcome to the Game Project\n";
    cout << "You can play at Tic T Toe\n";
    cout << "We working for the GUI UI.. Therfore u will play at console\n";
    UI* console = new Console();

    char** matrix = new char* [BORAD_SIZE];
    for (int i = 0; i < BORAD_SIZE; ++i) {
        matrix[i] = new char[BORAD_SIZE];
    }

    // init the matrix - from 1 to BORAD_SIZE^2


    for (int i = 0; i < BORAD_SIZE; i++)
        for (int j = 0; j < BORAD_SIZE; j++)
            matrix[i][j] = i * BORAD_SIZE + j + 1;
    
    printf("\n");

    cout << "What level you play\nComputer player is:\n";
    cout << "1. Educated Player\n";
    cout << "2. Random Player\n";
    int choice = 0;
    cin >> choice;
    Game* game;
    switch (choice)
    {
    case 1:
        game = new TicTacToeEdu(matrix);  //game ptr
        break;
    case 2:
        game = new TicTacToeRand(matrix);  //game ptr
        break;
    default:
        return 1;  //Exit
    }
   
    GameController* gc = new GameController(console, game);  //(UI, GAME)
    
    gc->Play();

}
