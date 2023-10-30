#include <iostream>
#define MMAX 30
#define TMax 20000
using namespace std;

int T, M;
int VData[MMAX + 1];
int PData[MMAX + 1];
int CalMatrix[MMAX + 1][TMax + 1];

void InitMatrix()
{
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            CalMatrix[i][j] = 0;
        }
    }
}

void CalRes()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (j >= VData[i] && CalMatrix[i - 1][j - VData[i]] + PData[i] > CalMatrix[i - 1][j])
            {
                CalMatrix[i][j] = CalMatrix[i - 1][j - VData[i]] + PData[i];
            }
            else
            {
                CalMatrix[i][j] = CalMatrix[i - 1][j];
            }
        }
    }
}

int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> VData[i];
        PData[i] = VData[i];
    }
    InitMatrix();
    CalRes();
    cout << T - CalMatrix[M][T] << endl;
    return 0;
}