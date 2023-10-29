#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 50000
using namespace std;

struct Cow
{
    int start;
    int end;
    int id;
};

bool smaller(Cow a, Cow b)
{
    return a.start < b.start;
}

Cow cows[MAXN];
int stallList[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i].start >> cows[i].end;
        cows[i].id = i;
    }
    sort(cows, cows + n, smaller);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> a;

    for (int i = 0; i < n; i++)
    {
        if(a.empty()||a.top().first >=cows[i].start){
            pair<int, int> temp;
            temp.first = cows[i].end;
            temp.second = a.size();
            stallList[cows[i].id] = temp.second;
            a.push(temp);
        }
        else{
            pair<int, int> temp = a.top();
            a.pop();
            temp.first = cows[i].end;
            stallList[cows[i].id] = temp.second;
            a.push(temp);
        }
        // if (maxstall == 0)
        // {
        //     stallList[cows[i].id] = 0;
        //     stallState[maxstall++] = cows[i].end;
        // }
        // else
        // {
        //     int stallId = 0;
        //     for (stallId = 0; stallId < maxstall; stallId++)
        //     {
        //         if (stallState[stallId] < cows[i].start)
        //         {
        //             findStall = true;
        //             stallState[stallId] = cows[i].end;
        //             break;
        //         }
        //     }
        //     if (!findStall)
        //     {
        //         maxstall++;
        //         stallState[stallId] = cows[i].end;
        //     }

        //     stallList[cows[i].id] = stallId;
        // }
    }
    cout << a.size() << endl;
    for (int i = 0; i < n; i++)
    {
        cout << stallList[i] + 1 << endl;
    }
    return 0;
}