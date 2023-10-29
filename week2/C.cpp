#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    string opt;
    cin >> N;
    set<string> t;
    while (N--)
    {
        cin >> opt;
        t.insert(opt);
    }
    cout << t.size();
}