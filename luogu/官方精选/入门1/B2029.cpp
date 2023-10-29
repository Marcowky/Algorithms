#include <bits/stdc++.h>
#define pi 3.14
using namespace std;

double h, r;

double cal_v() {
    return pi * r * r * h;
}

int main() {
    cin >> h >> r;
    cout << ceil(20 * 1000 / cal_v());
}