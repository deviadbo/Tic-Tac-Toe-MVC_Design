
#include "Console.h"
#include "Move.h"


Move Console::getPlayerMove()
{
    int choose;
    do
    {
        cin >> choose;
    } while (!(choose >= 1 && choose<=BORAD_SIZE*BORAD_SIZE));
    return (Move(choose));
}

void Console::printLine(const char* str)
{
    cout << str;
}

void Console::print(char** gameBoard)
{
    /*
    | 2 | 2 | 2 |
    | 2 | 2 | 2 |
    | 2 | 2 | 2 |
    */
    char slot;
    for (int i = 0; i < BORAD_SIZE; i++)
    {
        //cout << "|";
        for (int j = 0; j < BORAD_SIZE; j++)
        {
            cout << "| ";
            slot = gameBoard[i][j];
            if (slot == 'X')
                //cout << slot;
                cout << "X";
            else if (slot == 'O')
                //cout << slot;
                cout << "O";
            else
                cout << int(slot);
            cout << " ";
        }
        cout << "|";
        cout << "\n";
    }
    cout << "\n";
}



