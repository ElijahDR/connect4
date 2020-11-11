#include <iostream>
#include <vector>

using namespace std;

class Board
{
private:
    int data[7][7];
 
public:
    void makeZero();
    void print();
    void makeMove(int, int);
    bool checkPosition(int, int);
    bool checkDirection(int, int, int[]);
};

void Board::makeMove(int p, int x)
{
    for (int y = 7; y > 0; y--){
        if (data[y][x] == 0) {
            data[y][x] = p;
            break;
        }
    }
}

void Board::makeZero()
{
    for (int y = 0; y < 7; y++){
        for (int x = 0; x < 7; x++){
            data[y][x] = 0;
        }
    }
}

void Board::print()
{
    for (int y = 0; y < 7; y++){
        for (int x = 0; x < 7; x++){
            cout << data[y][x] << " ";
        }
        cout << "\n";
    }
}

bool Board::checkDirection(int X, int Y, int dir[2]){
    int p = data[Y][X];
    int checks[4] = {0,0,0,0};
    for (int i = 0; i < 4; i++){
        if (data[Y + (i * (dir[1]))][X + (i * (dir[0]))] == p){
            checks[i] = 1;
        } else {
            
        }
    }
}

bool Board::checkPosition(int X, int Y)
{
    int p = data[Y][X];
    // Check horizontally
    int rowCount = 0;
    for (int i = 0; i < 7; i++){
        if (data[Y][i] == p){
            rowCount++;
        }
    }

    if (rowCount >= 4){
        // Check right (positive X)
        int dir = [1, 0];
        if (data[Y][X+)
    }
}

int human = 1;
int ai = 2;

int main() {
    Board board;
    board.makeZero();
    board.makeMove(1, 1);
    board.print();

    cout << boolalpha << board.checkPosition(1, 3);
    
    return 0;
}