#include <cstring>
#include <iostream>
#include <queue>
#define MAXSIZE 400
using namespace std;

int chess_table[MAXSIZE][MAXSIZE];
bool has_visit[MAXSIZE][MAXSIZE];
int n, m;

int dir[8][2] = {{2, 1},  {1, 2},  {2, -1},  {-1, 2},
                 {-2, 1}, {1, -2}, {-2, -1}, {-1, -2}};

bool check(int x, int y) {
    bool temp = x >= 0 && x < n && y >= 0 && y < m;
    // cout <<x<<" "<<y<<" "<< temp << endl;
    return temp;
}

struct Point {
    int x, y;
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};

queue<Point> chess;

void bfs(int x, int y) {
    int sum = 0;
    chess_table[x][y] = 0;
    has_visit[x][y] = true;
    chess.push(Point(x, y));
    while (!chess.empty()) {
        Point front = chess.front();
        chess.pop();
        for (int i = 0; i < 8; i++) {
            int new_x = front.x + dir[i][0];
            int new_y = front.y + dir[i][1];

            if (check(new_x, new_y) && !has_visit[new_x][new_y]) {
                chess.push(Point(new_x, new_y));
                has_visit[new_x][new_y] = true;
                chess_table[new_x][new_y] = chess_table[front.x][front.y] + 1;
            }
        }
    }
}

int main() {
    int s_x, s_y;
    cin >> n >> m >> s_x >> s_y;
    s_x--;
    s_y--;
    memset(chess_table, -1, sizeof(chess_table));
    bfs(s_x, s_y);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << chess_table[i][j] << " ";
        }
        cout << endl;
    }
}