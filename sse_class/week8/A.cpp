#include <iostream>
#define MAXNUM 200000
using namespace std;

int n;
int dp_array[MAXNUM];
int data_array[MAXNUM];
int maxdata = -10000;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data_array[i];
    }
    dp_array[n - 1] = data_array[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (dp_array[i + 1] > 0)
            dp_array[i] = dp_array[i + 1] + data_array[i];
        else
            dp_array[i] = data_array[i];
    }
    for (int i = 0; i < n; i++)
    {
        // cin >> data_array[i];
        if (dp_array[i] > maxdata)
            maxdata = dp_array[i];
    }
    cout << maxdata << endl;
}