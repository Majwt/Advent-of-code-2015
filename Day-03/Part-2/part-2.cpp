#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> visited;
void make_move(pair<int, int>* cord, char direction);
vector<string> parse()
{
    ifstream input{"..//input.txt"};
    // stringstream input{"^>v<"};
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
    int x1, y1 = 0;
    int x2, y2 = 0;
    pair<int, int> cords1 = make_pair(x1, y1);
    pair<int, int> cords2 = make_pair(x2, y2);
    cout << cords1.first << " " << cords1.second << endl;
    cout << cords2.first << " " << cords2.second << endl << endl;

    visited[cords1] = true;
    vector<string> lines = parse();

    for (size_t i = 0; i < lines[0].size(); i++)
    {
        if (i & 1 == 1)
        {
            cout << "before:\t" << cords2.first << "\t" << cords2.second << endl; 
            make_move(&cords2, lines[0].at(i));
            cout << "after: \t" <<cords2.first << "\t" << cords2.second << endl; 
        }
        else
        {
            cout <<"before:\t" << cords1.first << "\t" << cords1.second << endl; 
            make_move(&cords1, lines[0].at(i));
            cout <<"after: \t" << cords1.first << "\t" << cords1.second << endl; 
        }
            visited[cords1] = true;
            visited[cords2] = true;
    }

    cout << visited.size() << endl;

    return 0;
}
void make_move(pair<int, int> *cord, char direction)
{
    switch (direction)
    {
    case '^':
        cord->second+= 1;
        break;
    case '>':
        cord->first+= 1;
        break;
    case 'v':
        cord->second-=1;
        break;
    case '<':
        cord->first-=1;
        break;
    default:
        break;
    }
}
