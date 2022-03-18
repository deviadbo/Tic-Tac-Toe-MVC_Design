

#include "TicTacToeEdu.h"


void  TicTacToeEdu::getComputerMove()
{
    Line maxLine;  //Will contain the row/column/diagonal with the maximum amount of free slots
    maxLine.emptySlot.SetMove(-1, -1);
    Line tmpLine;

    /* check for all rows */
    for (int i = 0; i < BORAD_SIZE; i++)
    {
        tmpLine = checkRow(i);
        /* check for optional line that doesnt have X and have maximum O*/
        //Defense
        if(tmpLine.PlayerSlotFilled == 2 && tmpLine.CompSlotFilled == 0 )
            {
                int i = tmpLine.emptySlot.getRowMove();
                int j = tmpLine.emptySlot.getColMove();
                m_board[i][j] = 'O';
                return;
            }
        
        //Attack
        if(maxLine.CompSlotFilled < tmpLine.CompSlotFilled && tmpLine.PlayerSlotFilled == 0 )
            maxLine = tmpLine;
    }

    /* check for all cells */
    for (int i = 0; i < BORAD_SIZE; i++)
    {
        tmpLine = checkCell(i);
        //Defense
        if(tmpLine.PlayerSlotFilled == 2 && tmpLine.CompSlotFilled == 0 )
            {
                int i = tmpLine.emptySlot.getRowMove();
                int j = tmpLine.emptySlot.getColMove();
                m_board[i][j] = 'O';
                return;
            }
        if(maxLine.CompSlotFilled < tmpLine.CompSlotFilled && tmpLine.PlayerSlotFilled == 0)
            maxLine = tmpLine;
    }

    /* check for diagonal */
    tmpLine = checkDiag();
    //Defense
    if(tmpLine.PlayerSlotFilled == 2 && tmpLine.CompSlotFilled == 0 )
        {
            int i = tmpLine.emptySlot.getRowMove();
            int j = tmpLine.emptySlot.getColMove();
            m_board[i][j] = 'O';
            return;
        }
    if(maxLine.CompSlotFilled < tmpLine.CompSlotFilled && tmpLine.PlayerSlotFilled == 0)
        maxLine = tmpLine;

    /* check for diagonal */
    tmpLine = checkRevDiag();
    //Defense
    if(tmpLine.PlayerSlotFilled == 2 && tmpLine.CompSlotFilled == 0 )
        {
            int i = tmpLine.emptySlot.getRowMove();
            int j = tmpLine.emptySlot.getColMove();
            m_board[i][j] = 'O';
            return;
        }
    if(maxLine.CompSlotFilled < tmpLine.CompSlotFilled && tmpLine.PlayerSlotFilled == 0)
        maxLine = tmpLine;


    /* Place X on empty slot on max line */
    //We got a line, where the number of 'O' is the largest
    if (maxLine.emptySlot.getColMove() != -1)
    {
        int i = maxLine.emptySlot.getRowMove();
        int j = maxLine.emptySlot.getColMove();
        m_board[i][j] = 'O';
    }
    else
    {
        RandomComputerMove();
    }
}
