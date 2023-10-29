#include <iostream>
#include <algorithm>
#define MAXN 1000
using namespace std;

int len_a, len_b;
string a, b;
int dp_array[MAXN][MAXN];

void init_array()
{
    for (int i = 0; i < max(len_a, len_b); i++)
    {
        dp_array[i][0] = 0;
        dp_array[0][i] = 0;
    }
}

int calLCS()
{
    for (int i = 0; i < len_a; i++)
    {
        for (int j = 0; j < len_b; j++)
        {
            if (a[i] == b[j])
                dp_array[i + 1][j + 1] = dp_array[i][j] + 1;
            else
                dp_array[i + 1][j + 1] = max(dp_array[i][j + 1], dp_array[i + 1][j]);
        }
    }

    return dp_array[len_a][len_b];
}

int main()
{
    while (cin >> a >> b)
    {
        len_a = a.size();
        len_b = b.size();
        init_array();
        cout << calLCS() << endl;
    }
}