#include <iostream>
#include <algorithm>
using namespace std;

string str;
int solve(int left, int right, char c)
{
    if (left == right)
    {
        if (c == str[left])
            return 0;
        else
            return 1;
    }
    int mid = (left + right) / 2;
    int res1 = 0, res2 = 0;
    for (int i = left; i <= mid; i++)
    {
        if (str[i] != c)
            res1++;
    }
    for (int i = mid + 1; i <= right; i++)
    {
        if (str[i] != c)
            res2++;
    }
    return min(res1 + solve(mid + 1, right, c + 1), res2 + solve(left, mid, c + 1));
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n >> str;
        cout << solve(0, n - 1, 'a') << endl;
    }
    return 0;
}