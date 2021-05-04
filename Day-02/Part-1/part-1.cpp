#include <bits/stdc++.h>
using namespace std;
size_t get_surfaceArea(vector<size_t> v);
int main()
{
    ifstream input{"..//input.txt"};
    string l, l2;
    size_t area = 0;
    while (getline(input, l))
    {
        vector<size_t> v;
        stringstream ss{l};

        while (getline(ss, l2, 'x'))
        {
            size_t a;
            stringstream parser{l2};
            parser >> a;
            v.push_back(a);
        }

        cout << l << endl;

        area += get_surfaceArea(v);
    }
    cout << area;
    return 0;
}
size_t get_surfaceArea(vector<size_t> v)
{
    vector<size_t> o;
    o.push_back(v.at(0) * v.at(1));
    o.push_back(v.at(1) * v.at(2));
    o.push_back(v.at(2) * v.at(0));
    sort(o.begin(), o.end());

    size_t area = 0;
    area += o.at(0);
    for (auto &&i : o)
    {
        area += 2 * i;
    }
    cout << area << endl;
    return area;
}