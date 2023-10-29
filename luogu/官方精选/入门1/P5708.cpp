#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

double a, b, c;

double getS() {
    double p = (a + b + c) / 2;
    double temp = p * (p - a) * (p - b) * (p - c);
    return pow(temp, 0.5);
}

int main() {
    cin >> a >> b >> c;
    printf("%0.1f", getS());
}