#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int num, temp;
    cin >> num;
    stack<pair<int, int>> s;
    stack<pair<int, int>> a;
    stack<int> final;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        a.push(make_pair(temp, i + 1));
    }
    for (int i = 0; i < num; i++)
    {
        while (!a.empty())
        {
            if (s.empty())
            {
                // cout << "0" << endl;
                final.push(0);
                s.push(a.top());
                a.pop();
            }
            else if (a.top().first >= s.top().first)
            {
                s.pop();
            }
            else
            {
                // cout << s.top().second << endl;
                final.push(s.top().second);
                s.push(a.top());
                a.pop();
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        cout << final.top() << " ";
        final.pop();
    }
}