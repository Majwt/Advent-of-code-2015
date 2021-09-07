#include <bits/stdc++.h>

using namespace std;
string Path = "..//input.txt";
// string Path = "..//example.txt";
map<string, map<string, int>> guide;
vector<string> visited;

void permute(string s, string answer)
{
    if (s.length() == 0)
    {
        cout << answer << " \n";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        permute(rest, answer + ch);
    }
}

bool findVisited(string name) {
    bool found = true;
    for (auto &&i : visited)
    {
        if (name == i) {
            found = false;
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
    int lowest = 1000;
    string n = "";
    for (auto &&j : guide[old])
    {
        
            if ((j.second < lowest) && (findVisited(j.first)))
            {
            n = j.first;
            lowest = j.second;
            // cout << lowest << endl;
                
            }

    }
    visited.push_back(n);
    tot += lowest;
    cout << n << endl;
    for (auto &&i : visited)
    {
        cout << i << " ";
    }

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

    for (auto &&i : guide)
    {
        cout << i.first << endl;
        for (auto &&j : i.second)
        {
            cout << j.first << " " << j.second << endl;
        }
        cout << endl;
    }
    // permute("abcdefg","");
    // recursion("London",10,0,visited);
    for (auto &&i : guide)
    {
        visited.push_back(i.first);
        cout << testing(i.first, 0) << endl;
        visited.clear();
    }

    return 0;
}