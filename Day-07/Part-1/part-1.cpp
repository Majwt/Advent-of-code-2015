#include <bits/stdc++.h>

using namespace std;

int n(int a)
{
    return (a ^ 0xffff);
}
map<string, int> theMap;

vector<string> alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
void init_values()
{

    ifstream input{"..//input.txt"};
    // ifstream input{"..//example.txt"};
    vector<string> rows;
    string l;
    while (getline(input, l))
    {
        stringstream parser{l};
        string first, second, to;
        parser >> first;
        parser >> second;
        if (isdigit(first[0]) && second == "->")
        {
            parser >> to;
            theMap[to] = stoi(first, nullptr, 10);
            cout << to << "\t" << theMap[to] << endl;
        }
        else
        {
            rows.push_back(l);
        }
    }
}

int main()
{
    ifstream input{"..//input.txt"};
    // ifstream input{"..//example.txt"};
    string l;
    init_values();
    while (getline(input, l))
    {
        cout << l << endl;
    }
    // cout << n(7) << '\n';

    for (auto &&i : theMap)
    {
        cout << i.first << "\t" << i.second << endl;
    }

    return 0;
}
