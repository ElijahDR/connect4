#include <iostream>
#include <vector>

using namespace std;

int HEIGHT = 6;
int WIDTH = 7;

class Board
{
private:
    int data[7][7];
 
public:
    void makeZero();
    void print();
    void makeMove(int, int);
    bool checkPosition(int);
    bool checkDirection(int, int, int[]);
    bool canMove(int);
};

bool Board::canMove(int x)
{
    if (data[0][x] == 0){
        return true;
    } else {
        return false;
    }
}

void Board::makeMove(int p, int x)
{
    for (int y = HEIGHT-1; y >= 0; y--){
        if (data[y][x] == 0) {
            data[y][x] = p;
            break;
        }
    }
}

void Board::makeZero()
{
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            data[y][x] = 0;
        }
    }
}

void Board::print()
{
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            cout << (data[y][x] == 1 ? " X " : (data[y][x] == 2 ? " O " : " . "));
        }
        cout << "\n";
    }
}

bool Board::checkDirection(int X, int Y, int dir[2]){
    int p = data[Y][X];
    int streakPos = 0;
    for (int i = 1; i < 4; i++){
        if (data[Y + (i * (dir[1]))][X + (i * (dir[0]))] == p){
            streakPos++;
        } else {
            break;
        }
    }
    int streakNeg = 0;
    dir[0] *= -1;
    dir[1] *= -1;
    for (int i = 1; i < 4; i++){
        if (data[Y + (i * (dir[1]))][X + (i * (dir[0]))] == p){
            streakNeg++;
        } else {
            break;
        }
    }
    if (streakPos + streakNeg + 1 >= 4){
        return true;
    } else {
        return false;
    }
}

bool Board::checkPosition(int X)
{
    int Y;
    for (int i = 0; i < HEIGHT; i++){
        if (data[i][X] != 0){
            Y = i;
            break;
        }
    }
    int p = data[Y][X];
    // Check horizontally and vertically
    int rowCount = 0;
    int colCount = 0;
    for (int i = 0; i < WIDTH; i++){
        if (data[Y][i] == p){
            rowCount++;
        }
        if (i < HEIGHT){
            if (data[i][X] == p){
                colCount++;
            }
        }
    }

    if (rowCount >= 4){
        int dir[2] = {1, 0};
        bool check = checkDirection(X, Y, dir);
        if (check) {
            return true;
        }
    }
    if (colCount >= 4){
        int dir[2] = {0, 1};
        bool check = checkDirection(X, Y, dir);
        if (check) {
            return true;
        }
    }

    // Check diagonally (positive gradient)
    int dir[2] = {1,1};
    bool check = checkDirection(X, Y, dir);
    if (check) {
        return true;
    }

    dir[0] = -1;
    check = checkDirection(X, Y, dir);
    if (check) {
        return true;
    }

    return false;
}

int human = 1;
int ai = 2;

int main() {
    Board board;
    board.makeZero();
    board.makeMove(1, 1);
    board.makeMove(1, 1);
    board.makeMove(1, 1);
    board.makeMove(2, 1);
    board.print();

    cout << boolalpha << board.checkPosition(1) << endl;
    
    return 0;
}