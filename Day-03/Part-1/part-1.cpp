#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> visited;
vector<string> parse()
{
    ifstream input{"..//input.txt"};
    vector<string> line;
    string l;
    while (getline(input, l))
    {
        line.push_back(l);
    }
    return line;
}
int main()
{
    int x, y = 0;
    pair<int,int> cords = make_pair(x,y);
    visited[cords] = true;
    vector<string> lines = parse();
    for (auto &&i : lines)
    {
        for (auto &&j : i)
        {
            switch (j)
            {
            case '^':
                cords.second++;
                break;
            case 'v':
                cords.second--;
                break;
            case '>':
                cords.first++;
                break;
            case '<':
                cords.first--;
                break;
            default:
                break;
            }
            
            visited[cords] = true;
        }
        
    }
    cout << visited.size() << endl;

    return 0;
}