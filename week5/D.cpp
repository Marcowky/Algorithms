#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num, a[100], avg = 0;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
        avg += a[i];
    }
    avg /= num;
    for (int i = 0; i < num; i++)
    {
        a[i] -= avg;
    }
    int i = 0, res = 0;
    while (true)
    {
        while (a[i] == 0 && i < num - 1)
            i++;
        if (i == num - 1)
            break;
        a[i + 1] += a[i];
        a[i] = 0;
        res++;
    }
    cout << res << endl;

    return 0;
}