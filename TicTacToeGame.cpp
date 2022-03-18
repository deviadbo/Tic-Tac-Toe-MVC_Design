#include "TicTacToeGame.h"


void TicTacToeGame::updateGameState()
{
    /* check for all rows */
    Line tmp;
    int compCount;
    int plrCount;
    for (int i = 0; i < BORAD_SIZE; i++)
    {
        tmp = checkRow(i);
        compCount = tmp.CompSlotFilled;
        plrCount = tmp.PlayerSlotFilled;
        if (compCount == BORAD_SIZE)
        {
            m_state = ComputerWin;
            return;
        }
        else if (plrCount == BORAD_SIZE)
        {
            m_state = PlayerWin;
            return;
        }
    }

    /* check for all cells */
    for (int i = 0; i < BORAD_SIZE; i++)
    {
        tmp = checkCell(i);
        compCount = tmp.CompSlotFilled;
        plrCount = tmp.PlayerSlotFilled;
        if (compCount == BORAD_SIZE)
        {
            m_state = ComputerWin;
            return;
        }
        else if (plrCount == BORAD_SIZE)
        {
            m_state = PlayerWin;
            return;
        }
    }

    /* check for diagonal */
    tmp = checkDiag();
    compCount = tmp.CompSlotFilled;
    plrCount = tmp.PlayerSlotFilled;
    if (compCount == BORAD_SIZE)
    {
        m_state = ComputerWin;
        return;
    }
    else if (plrCount == BORAD_SIZE)
    {
        m_state = PlayerWin;
        return;
    }

    /* check for diagonal */
    tmp = checkRevDiag();
    compCount = tmp.CompSlotFilled;
    plrCount = tmp.PlayerSlotFilled;
    if (compCount == BORAD_SIZE)
    {
        m_state = ComputerWin;
        return;
    }
    else if (plrCount == BORAD_SIZE)
    {
        m_state = PlayerWin;
        return;
    }

    /* check for tie */
    int countFullSlot = 0;
    char slot;
    for(int i = 0; i < BORAD_SIZE; i++)
        for (int j = 0; j < BORAD_SIZE; j++)
        {
            slot = m_board[i][j];
            if (slot == 'X' || slot == 'O')
                countFullSlot++;
        }
    if (countFullSlot == BORAD_SIZE * BORAD_SIZE)
        m_state = Tie;
    else
        m_state = inGame;
}

GameState TicTacToeGame::getGameState()
{
    return m_state;
}

Result TicTacToeGame::setPlayerMove(Move move)
{
    int i = move.getRowMove();
    int j = move.getColMove();
    char slot = m_board[i][j];
    if (slot != 'X' && slot != 'O' && (i >= 0 && i < BORAD_SIZE) && (j >= 0 && j < BORAD_SIZE))
        m_board[i][j] = 'X';
    else
        return WrongMove;
    return Success;
}

/*
    The function slots the position of the computer player in a random slot.
    The function will be used by us in both stages of the game.
    It is therefore in this position in the hierarchy.
*/
void TicTacToeGame::RandomComputerMove()
{
    //No need to check if the Board is full, Because the USER have the last turn (even turn)
    bool freeSlot = false;
    do
    {
        srand(time(NULL));
        int row = rand() % (BORAD_SIZE );
        int col = rand() % (BORAD_SIZE );
        // if the slot is free - then - will put there O
        // else - Random
        if (m_board[row][col] != 'X' && m_board[row][col] != 'O')
        {
            freeSlot = true;
            m_board[row][col] = 'O';
        }
    } while (!freeSlot);
}


Line TicTacToeGame::checkDiag()
{
    int O_count = 0;
    int X_count = 0;

    Line diagLine(Diag ,0 ,0, 0);
    diagLine.emptySlot.SetMove(-1, -1);

    for (int i = 0; i < BORAD_SIZE; i++)
    {
        //run over the diagonal
        if (m_board[i][i] != 'O' && m_board[i][i] != 'X')
            diagLine.emptySlot.SetMove(i, i);
        else if (m_board[i][i] == 'O')
            O_count++;
        else if (m_board[i][i] == 'X')
        {
            X_count++;
            //O_count = 0;
            //break;  // can cause breaking without filling data
        }
    }
    diagLine.CompSlotFilled = O_count;
    diagLine.PlayerSlotFilled = X_count;
    return diagLine;
}

Line TicTacToeGame::checkRevDiag()
{
    int O_count = 0;
    int X_count = 0;
    Line revDiagLine(revDiag,0, 0, 0);
    revDiagLine.emptySlot.SetMove(-1, -1);

    // i  j
    // 0,2
    // 1,1
    // 2,0
    int j = BORAD_SIZE -1;
    int i = 0;
    for (; i < BORAD_SIZE; )
    {
        if (m_board[i][j] != 'O' && m_board[i][j] != 'X')
            revDiagLine.emptySlot.SetMove(i, j);
        else if (m_board[i][j] == 'O')
            O_count++;
        else if (m_board[i][j] == 'X')
        {
            X_count++;
            //O_count = 0;
            //break;  // can cause breaking without filling data
        }
        i++; j--;
    }
    revDiagLine.CompSlotFilled = O_count;
    revDiagLine.PlayerSlotFilled = X_count;
    return revDiagLine;
}

//Attack Mode -   Computer look for win only
Line TicTacToeGame::checkRow(int i)
{
    int O_count = 0;
    int X_count = 0;
    Line rowLine(Row ,0, 0, 0 );
    rowLine.emptySlot.SetMove(-1, -1); // default for free slot

    for (int j = 0; j < BORAD_SIZE; j++)
    {
        if (m_board[i][j] != 'O' && m_board[i][j] != 'X')
            rowLine.emptySlot.SetMove(i, j); //save empty slot index
        else if (m_board[i][j] == 'O')
            O_count++;
        else if (m_board[i][j] == 'X')
        {
            X_count++;
            //O_count = 0;
            //break;  // can cause breaking without filling data
            //In a row that has an X, the computer cannot fill a copmlete line
        }
    }
    rowLine.CompSlotFilled = O_count;
    rowLine.PlayerSlotFilled = X_count;
    return rowLine;
}

Line TicTacToeGame::checkCell(int j)
{
    int O_count = 0;
    int X_count = 0;
    Line cellLine(Cell ,0, 0, 0 );
    cellLine.emptySlot.SetMove(-1, -1);

    for (int i = 0; i < BORAD_SIZE; i++)
    {
        if (m_board[i][j] != 'O' && m_board[i][j] != 'X')
            cellLine.emptySlot.SetMove(i, j);
        else if (m_board[i][j] == 'O')
            O_count++;
        else if (m_board[i][j] == 'X')
        {
            X_count++;
        }
    }
    cellLine.CompSlotFilled = O_count;
    cellLine.PlayerSlotFilled = X_count;
    return cellLine;
}
