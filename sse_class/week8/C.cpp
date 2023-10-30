#include <iostream>
#include <algorithm>
#define MAXN 5000
#define MOD 100000000
using namespace std;

int len_a, len_b;
string a, b;
int dp_array[2][MAXN];
int dp_num_array[2][MAXN];

void init_array()
{
    for (int i = 0; i < max(len_a, len_b); i++)
    {
        dp_array[0][i] = 0;
        dp_array[1][i] = 0;
        dp_num_array[0][i] = 1;
    }
    dp_num_array[1][0] = 1;
}

void cal_LCS()
{
    for (int i = 0; i < len_a; i++)
    {
        for (int j = 0; j < len_b; j++)
        {
            dp_num_array[(i + 1) % 2][j + 1] = 0;
            if (a[i] == b[j])
            {
                dp_array[(i + 1) % 2][j + 1] = dp_array[i % 2][j] + 1;
                dp_num_array[(i + 1) % 2][j + 1] += dp_num_array[i % 2][j] % MOD;
            }
            else
            {
                dp_array[(i + 1) % 2][j + 1] = max(dp_array[i % 2][j + 1], dp_array[(i + 1) % 2][j]);
            }
            if (dp_array[(i + 1) % 2][j + 1] == dp_array[i % 2][j + 1])
            {
                dp_num_array[(i + 1) % 2][j + 1] += dp_num_array[i % 2][j + 1] % MOD;
            }
            if (dp_array[(i + 1) % 2][j + 1] == dp_array[(i + 1) % 2][j])
            {
                dp_num_array[(i + 1) % 2][j + 1] += dp_num_array[(i + 1) % 2][j] % MOD;
            }
            if (a[i] != b[j] && dp_array[(i + 1) % 2][j + 1] == dp_array[i % 2][j])
            {
                dp_num_array[(i + 1) % 2][j + 1] -= dp_num_array[i % 2][j] % MOD;
            }
        }
    }
}

int main()
{
    cin >> a >> b;
    len_a = a.size() - 1;
    len_b = b.size() - 1;
    init_array();
    cal_LCS();
    cout << dp_array[len_a % 2][len_b] << endl
         << dp_num_array[len_a % 2][len_b] << endl;
}