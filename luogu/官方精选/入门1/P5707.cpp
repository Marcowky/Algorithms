#include <bits/stdc++.h>
using namespace std;
double s, v, m;
int n, a, t, b;
int main() {
    cin >> s >> v;
    n = 8 * 60 + 24 * 60;  // 两天总共的分钟数
    t = ceil(s / v) +
        10;  // ceil()很重要，向上取整，否则按C++逻辑会向下取整导致行走时间少。
    n = n - t;  // 得出剩下的时间。
    if (n >= 24 * 60)
        n -= 24 * 60;  // 判断是否在前一天。
    b = n % 60;        // 得出出发分。
    a = n / 60;        // 得出出发时
    cout << setw(2) << setfill('0') << a << ":";
    cout << setw(2) << setfill('0') << b << endl;
    return 0;
}