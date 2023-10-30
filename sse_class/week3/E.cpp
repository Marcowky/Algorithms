#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    int n, r, total = 0;
    cin >> n >> r;
    stack<stack<int>> result;
    for (int i = 0; i < (1 << n); i++)
    {
        stack<int> temp;
        int resultnum = 0;
        int tempnum = i;
        for (int j = 0; j < n; j++)
        {
            if (tempnum & (1 << j))
            {
                temp.push(n - j);
                resultnum++;
            }
        }
        if (resultnum == r)
        {
            total++;
            result.push(temp);
        }
    }
    while (!result.empty())
    {
        while (!result.top().empty())
        {
            cout << setw(3) << result.top().top();
            result.top().pop();
        }
        cout << endl;
        result.pop();
    }
}