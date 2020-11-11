#ifndef BOARD_H
#define BOARD_H
 
class Board
{
private:
    int data[7][7];
 
public:
    void makeMove(int, int, int);
    int checkPosition(int, int);
};
 
#endif