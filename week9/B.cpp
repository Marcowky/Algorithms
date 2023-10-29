#include <algorithm>
#include <cstdlib>
#include <iostream>
#define MAXSIZE 20
using namespace std;

int timeData[4][MAXSIZE];
int num[4];
int res[4];
int rest[4];

void cal(int num, int i) {
    if (timeData[i][num] - rest[i] >= 0) {
        rest[i] = timeData[i][num] - rest[i];
        res[i] += rest[i];
    } else {
        rest[i] -= timeData[i][num];
    }
    if (num == 0) {
        return;
    }
    cal(num - 1, i);
    return;
}

int main() {
    int res_sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> num[i];
        res[i] = 0;
        rest[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < num[i]; j++) {
            cin >> timeData[i][j];
        }
        // 对数组排序
        sort(timeData[i], timeData[i] + num[i]);
    }
    for (int i = 0; i < 4; i++) {
        cal(num[i] - 1, i);
        res_sum += res[i];
    }
    cout << res_sum << endl;
}

// 不对 如 5 4 3 3 3