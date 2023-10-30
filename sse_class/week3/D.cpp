#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int n, m;
    int num[1000];
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            num[i] = i;
        }
        int temp = 1;
        while (temp < m)
        {
            next_permutation(num + 1, num + n + 1);
            temp++;
        }
        for (int i = 1; i <= n; i++)
            cout << num[i] << " ";
        cout << endl;
    }
}