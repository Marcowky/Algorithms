#include <iostream>
#include <cmath>
#define MAX_NUM 1000
using namespace std;

int chess_board[MAX_NUM][MAX_NUM], chess_size, numL;

void addL(int sp_x, int sp_y, int mid_x, int mid_y, int size)
{
    if (size <= 1)
        return;
    int curNum = numL++;
    int new_size = size / 2;
    // cout << sp_x << " " << sp_y << " " << mid_x << " " << mid_y << " " << size << " " << curNum << endl;
    if (sp_x < mid_x && sp_y < mid_y)
    {
        addL(sp_x, sp_y, mid_x - new_size / 2, mid_y - new_size / 2, new_size);
    }
    else
    {
        chess_board[mid_x - 1][mid_y - 1] = curNum;
        addL(mid_x - 1, mid_y - 1, mid_x - new_size / 2, mid_y - new_size / 2, new_size);
    }
    if (sp_x < mid_x && sp_y >= mid_y)
    {

        addL(sp_x, sp_y, mid_x - new_size / 2, mid_y + new_size / 2, new_size);
    }
    else
    {
        chess_board[mid_x - 1][mid_y] = curNum;
        addL(mid_x - 1, mid_y, mid_x - new_size / 2, mid_y + new_size / 2, new_size);
    }
    if (sp_x >= mid_x && sp_y < mid_y)
    {
        addL(sp_x, sp_y, mid_x + new_size / 2, mid_y - new_size / 2, new_size);
    }
    else
    {
        chess_board[mid_x][mid_y - 1] = curNum;
        addL(mid_x, mid_y - 1, mid_x + new_size / 2, mid_y - new_size / 2, new_size);
    }

    if (sp_x >= mid_x && sp_y >= mid_y)
    {

        addL(sp_x, sp_y, mid_x + new_size / 2, mid_y + new_size / 2, new_size);
    }
    else
    {
        chess_board[mid_x][mid_y] = curNum;
        addL(mid_x, mid_y, mid_x + new_size / 2, mid_y + new_size / 2, new_size);
    }
}

void dispChess()
{

    for (int i = 0; i < chess_size; i++)
    {
        for (int j = 0; j < chess_size; j++)
        {
            cout << chess_board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int k, x, y;
    cin >> k >> x >> y;
    numL = 1;
    x--;
    y--;
    chess_size = pow(2, k);
    chess_board[x][y] = 0;
    addL(x, y, chess_size / 2, chess_size / 2, chess_size);
    dispChess();
}