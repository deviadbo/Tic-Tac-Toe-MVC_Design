#include "Move.h"
#include "GameController.h"


Move:: Move(int slot)
{
        //Converts the slot number, to the matrix cell
        if (slot % BORAD_SIZE == 0)
            {col = BORAD_SIZE - 1;
            row = slot / BORAD_SIZE -1;}
        else
            {col = slot % BORAD_SIZE - 1;
            row = slot / BORAD_SIZE;}
}
/*
1|2|3
4|5|6
7|8|9
*/

Move::Move(int r, int c)
{
    col = c;
    row = r;
}





