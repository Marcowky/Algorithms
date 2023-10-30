#include <iostream>
#define MAXSIZE 20
#define CHECK(x, y) (x < size_h && x >= 0 && y < size_w && y >= 0)
using namespace std;

char a[MAXSIZE][MAXSIZE];
int size_w, size_h, res, s_x, s_y;
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


void dfs(int x, int y) {
    a[x][y] = '#';
    res++;
    int new_x, new_y;
    for (int i = 0; i < 4; i++) {
        new_x = x + dir[i][0];
        new_y = y + dir[i][1];
        if (CHECK(new_x, new_y) && a[new_x][new_y] == '.') {
            dfs(new_x, new_y);
        }
    }
}

int main() {
    while (cin >> size_w >> size_h && (size_w + size_h)) {
        for (int i = 0; i < size_h; i++) {
            for (int j = 0; j < size_w; j++) {
                cin >> a[i][j];
                if (a[i][j] == '@') {
                    s_x = i;
                    s_y = j;
                }
            }
        }
        res = 0;
        dfs(s_x, s_y);
        cout << res << endl;
        // for (int i = 0; i < size_h; i++) {
        //     for (int j = 0; j < size_w; j++) {
        //         cout << a[i][j];
        //     }
        //     cout << endl;
        // }
    }
}