#include <iostream>
using namespace std;

double cal_money(int yy, int jj) {
    return yy * 10 + jj;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << (int)(cal_money(a, b) / cal_money(1, 9));
}