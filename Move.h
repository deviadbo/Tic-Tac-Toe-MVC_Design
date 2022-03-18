#pragma once
class Move
{
public:
    Move(int);
    Move(int r, int c);
    Move() {}  //defult C'tor

public:
    void SetMove(int r, int c) {  row = r; col = c;}
    int getColMove() { return col; }
    int getRowMove() { return row; }
protected:
    int col;
    int row;
};

/*
1|2|3
4|5|6
7|8|9
*/
