#include <iostream>
#include <queue>
using namespace std;

struct patient
{
    int level, pos;
    friend bool operator<(patient a, patient b)
    {
        if (a.level == b.level)
        {
            return a.pos > b.pos;
        }
        return a.level < b.level;
    }
};

int main()
{
    int N;
    string opt;

    while (cin >> N)
    {
        int pos = 1;
        priority_queue<patient> doctor[3];
        while (N--)
        {
            cin >> opt;
            int a, b;
            if (opt == "IN")
            {
                cin >> a >> b;
                a--;
                doctor[a].push({b, pos});
                pos++;
            }
            else if (opt == "OUT")
            {
                cin >> a;
                a--;
                if (doctor[a].empty())
                {
                    cout << "EMPTY\n";
                }
                else
                {
                    cout << doctor[a].top().pos << endl;
                    doctor[a].pop();
                }
            }
        }
    }
}