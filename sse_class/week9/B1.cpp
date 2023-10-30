#include <iostream>
#define MAXSIZE 20
using namespace std;

int timeData[4][MAXSIZE];
int num[4];
int left_brain, right_brain, res;

void dfs(int i, int index) {
    if (index >= num[i]) {
        res = min(res, max(left_brain, right_brain));
        return;
    }
    left_brain += timeData[i][index];
    dfs(i, index + 1);
    left_brain -= timeData[i][index];
    right_brain += timeData[i][index];
    dfs(i, index + 1);
    right_brain -= timeData[i][index];
}

int main() {
    int res_sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        left_brain = right_brain = 0;
        res = 1e9;
        for (int j = 0; j < num[i]; j++) {
            cin >> timeData[i][j];
        }
        dfs(i, 0);
        res_sum += res;
    }
    cout << res_sum << endl;
}