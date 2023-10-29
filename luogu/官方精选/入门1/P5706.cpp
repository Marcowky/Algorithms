#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    double total;
    int num;
    cin >> total >> num;
    printf("%0.3f\n%d", total / num, num * 2);
}