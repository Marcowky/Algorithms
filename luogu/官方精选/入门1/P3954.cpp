#include <iostream>
using namespace std;

double a, b, c;

int cal_mark() {
    return a * 0.2 + b * 0.3 + c * 0.5;
}

int main() {
    cin >> a >> b >> c;
    cout << cal_mark();
}