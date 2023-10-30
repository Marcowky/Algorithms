#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> a;

int main()
{
    int n;
    while (cin >> n && n)
    {
        a.resize(0);
        for (int i = 0; i < n; i++)
        {
            int start, end;
            cin >> start >> end;
            a.push_back(make_pair(end, start));
        }
        sort(a.begin(), a.end());
        int res = 1, temp = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].second >= a[temp].first)
            {
                res++;
                temp = i;
            }
        }
        cout << res << endl;
    }
    return 0;
}