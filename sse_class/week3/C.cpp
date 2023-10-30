#include <iostream>
using namespace std;

int main()
{
    int n, casenum = 1;
    while (cin >> n)
    {
        int num[18];
        long long maxnum = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        for (int i = 0; i < n; i++)
        {
            cur = num[i];
            for (int j = i; j < n; j++)
            {
                if (i != j)
                    cur = cur * num[j];
                if (cur > maxnum)
                    maxnum = cur;
            }
        }
        cout << "Case #" << casenum << ": The maximum product is " << maxnum << "." << endl
             << endl;
        casenum++;
    }
}