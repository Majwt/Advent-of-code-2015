#include <bits/stdc++.h>

using namespace std;
string Path = "..//input.txt";
// string Path = "..//example.txt";
map<string, map<string, int>> guide;
vector<string> visited;

bool findVisited(string name)
{
    bool found = false;
    for (auto &&i : visited)
    {
        if (name == i)
        {
            found = true;
        }
    }
    return found;
}
int testing(string old, int tot)
{
    if (visited.size() >= 8)
    {
        return tot;
    }
    int lowest = 0;
    string n = "";
    for (auto &&j : guide[old])
    {
        if ((j.second > lowest) && (!findVisited(j.first)))
        {
            n = j.first;
            lowest = j.second;
        }
    }
    visited.push_back(n);
    tot += lowest;
    return testing(n, tot);
}

int main()
{
    ifstream input{Path};
    string l;

    while (getline(input, l))
    {
        if (l.empty())
        {
            continue;
        }
        stringstream parser{l};
        string name, to;
        int dist;
        parser >> name;
        parser.ignore(3);
        parser >> to;
        parser >> dist;
        guide[name][to] = dist;
        cout << l << endl;
    }
map<int,string> Pathing;
    for (auto &&i : guide)
    {
        visited.push_back(i.first);
        int temp = testing(i.first,0);
        
            string temp2 ="";
        for (auto &&i : visited)
        {
            temp2+= i+"\t-> ";
        }
             Pathing[temp] = temp2;

        visited.clear();
    }
for (auto &&i : Pathing)
{
    cout << i.first << "\t" << i.second << endl;
}

    return 0;
}