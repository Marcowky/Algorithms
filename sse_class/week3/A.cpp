#include <iostream>
using namespace std;

int main()
{
    long long l, r, k, p;
    bool label;
    while (cin >> l >> r >> k)
    {
        long long p = 1;
        label = false;
        while (true)
        {
            if (p >= l && p <= r)
            {
                cout << p << " ";
                label = true;
            }
            if (p > r / k)
            {
                break;
            }
            p = p * k;
        }
        if (!label)
        {
            cout << -1 << endl;
        }
        else
            cout << endl;
    }
}