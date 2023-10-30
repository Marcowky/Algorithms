#include <iostream>
#include <algorithm>
#define NMAX 1e6
#define MMAX 1000
#define RMAX 1e6
using namespace std;

int N, M, R;
int PArray[MMAX + 1], DArray[MMAX + 1];

struct Node
{
    int startTime;
    int endTime;
    int value;
} timeNode[MMAX + 1];

bool smaller(Node a, Node b)
{
    return a.endTime < b.endTime;
}

void CalPArray()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (timeNode[j].endTime <= timeNode[i].startTime)
            {
                PArray[i] = j;
                break;
            }
        }
    }
}

void CalDArray()
{
    DArray[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        DArray[i] = max(DArray[PArray[i]] + timeNode[i].value, DArray[i - 1]);
    }
}

int main()
{
    cin >> N >> M >> R;
    N += R;

    for (int i = 1; i <= M; i++)
    {
        cin >> timeNode[i].startTime >> timeNode[i].endTime >> timeNode[i].value;
        timeNode[i].endTime += R;
    }

    sort(timeNode + 1, timeNode + M + 1, smaller);
    CalPArray();
    CalDArray();
    cout << DArray[M] << endl;

    return 0;
}