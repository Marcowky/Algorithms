#include <iostream>
using namespace std;

long long getAns(int n)
{
    if (n == 1 || n == 2)
        return n;
    n -= 1;
    long long low = 1, high = 2, temp;
    while (n--)
    {
        temp = high;
        high = low + high;
        low = temp;
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    // long long low = 1, high = 2;
    cout << getAns(n) << endl;
    return 0;
}