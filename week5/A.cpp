#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> a;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push(temp);
    }

    while (a.size() > 1)
    {
        int s1 = a.top();
        a.pop();
        int s2 = a.top();
        a.pop();
        a.push(s1 + s2);
        res += s1 + s2;
    }
    cout << res << endl;
    return 0;
}