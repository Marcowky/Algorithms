#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    string n;
    cin >> n >> num;
    while (num--)
    {
        int i = 0;
        while (i < n.size() && n[i] <= n[i + 1])
            i++;
        n.erase(i, 1);
    }
    while (n.size() > 1 && n[0] == '0')
        n.erase(0, 1);
    cout << n << endl;
    return 0;
}