#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long getHash(string str)
{
    long long res = 0;
    int base = 65537;
    int mod = 1e9+7;
    for (int i = 0; i < str.size(); i++)
    {
        res = (res * base + (str[i] - 'a')) % mod;
    }
    return res;
}

int main()
{
    int pos = 0, N;
    string spell, func, input;
    vector<string> myDict;
    map<int, int> myMap;
    while (getline(cin, input) && input != "@END@")
    {
        int temp = input.find("]");
        spell = input.substr(0, temp + 1);
        func = input.substr(temp + 2, input.length() - 1);
        myDict.push_back(spell);
        myDict.push_back(func);
        myMap[getHash(spell)] = pos + 1;
        myMap[getHash(func)] = pos;
        pos += 2;
    }
    cin >> N;
    getchar();
    while (N--)
    {
        getline(cin, input);
        if (myMap[getHash(input)] > 0)
        {
            string temp = myDict[myMap[getHash(input)]];
            if (input[0] == '[')
            {
                cout << temp << endl;
            }
            else
            {
                cout << temp.substr(1, temp.length() - 2) << endl;
            }
        }
        else
        {
            cout << "what?" << endl;
        }
    }
}