#include <iostream>
using namespace std;

double cal_min(int hh, int mm) {
    return hh * 60 + mm;
}

void show_time(int mm) {
    cout << mm / 60 << " " << mm % 60;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    show_time(cal_min(c, d) - cal_min(a, b));
}