#include <iostream>
using namespace std;

bool isCorNum(int a, int b)
{
    bool temp[10] = {false};
    for (int i = 0; i < 5; i++)
    {
        int aa = a % 10, bb = b % 10;
        a = a / 10;
        b = b / 10;
        if (!temp[aa] && !temp[bb] && aa != bb)
        {
            temp[aa] = true;
            temp[bb] = true;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, res, casenum = 1;
    bool label;
    string str;
    while (cin >> n && n)
    {
        if (casenum > 1)
        {
            printf("\n");
        }
        casenum++;
        label = false;
        for (int i = 1234; i < 98765; i++)
        {
            res = i * n;
            if (i > res || res > 98765)
                break;
            if (isCorNum(res, i))
            {
                printf("%05d / %05d = %d\n", res, i, n);
                label = true;
            }
        }
        if (!label)
        {
            printf("There are no solutions for %d.\n", n);
        }
    }
}