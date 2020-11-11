#include "Board.h"

void Board::makeMove(int p, int x, int y)
{
    if (data[y][x] == 0){
        data[y][x] = p;
    }
}