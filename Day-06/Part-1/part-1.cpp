#include <bits/stdc++.h>

using namespace std;
vector<vector<bool>> positions;
void fill()
{
    vector<bool> temp;
    for (size_t i = 0; i < 1000; i++)
    {
        temp.push_back(false);
    }
    for (size_t i = 0; i < 1000; i++)
    {
        positions.push_back(temp);
    }
}
void toggle(int x, int y)
{
    bool temp = positions.at(y).at(x);
    positions.at(y).at(x) = !temp;
}
void turn_off(int x, int y)
{
    positions.at(y).at(x) = false;
}

void turn_on(int x, int y)
{
    positions.at(y).at(x) = true;
}
struct instructions {
    char name;
    pair<int,int> c1;
    pair<int,int> c2;
};
void through(instructions inst)
{
    inst.c1.first;
    for (size_t y = inst.c1.second; y <= inst.c2.second; y++)
    {
        for (size_t x = inst.c1.first; x <= inst.c2.first; x++)
        {
            switch (inst.name)
            {
            case 'o':
                toggle(x,y);
                break;
            case 'n':
                turn_on(x,y);
                break;
            case 'f':
                turn_off(x,y);
                break;
            default:
                cout << "broke\n";
                break;
            }
        }
    }
}
void through(pair<int,int> c1, pair<int,int> c2, char name)
{
    for (size_t y = c1.second; y <= c2.second; y++)
    {
        for (size_t x = c1.first; x <= c2.first; x++)
        {
            switch (name)
            {
            case 'o':
                toggle(x,y);
                break;
            case 'n':
                turn_on(x,y);
                break;
            case 'f':
                turn_off(x,y);
                break;
            default:
                cout << "broke\n";
                break;
            }
        }
    }
}
vector<instructions> parse() {
    ifstream input{"..//input.txt"};
    string l;
    vector<instructions> out;
    while (getline(input,l)) {
        instructions inst;
        string name;
        int x1,y1;
        int x2,y2;
        stringstream parser{l};
        parser >> name;
        parser >> x1 >> y1;
        parser.ignore(8);
        parser >> x2 >> y2;
        // cout << x1 << " " << y1 << endl << x2 << " " << y2 << endl;
        inst.name = name[1];
        inst.c1 = make_pair(x1,y1);
        inst.c2 = make_pair(x2,y2);
        out.push_back(inst);
        inst = {};
    }
    return out;
}
void on_count() {
    size_t counter = 0;
    for (auto &&i : positions)
    {
        for (auto &&j : i)
        {
            if (j) {
                counter++;
            }
        }
    }
    cout << counter << endl;
}
int main()
{
    fill();
    vector<instructions> inst = parse();
    for (auto &&i : inst)
    {
        // through(inst[0]);
        through(i);
    }
    // through(make_pair(0,0),make_pair(999,999),'n');
    // through(make_pair(0,0),make_pair(999,0),'o');
    // through(make_pair(499,499),make_pair(500,500),'f');
    // toggle(100,0);
    on_count();
    // cout << boolalpha << positions[0][100];


    return 0;
}