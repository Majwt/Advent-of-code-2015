#include <bits/stdc++.h>
using namespace std;
size_t get_ribbon(vector<size_t> v);
size_t get_bow(vector<size_t> v);
size_t get_wrap(vector<size_t> v);
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
        area += get_ribbon(v);
        v.clear();
    }
    cout << area;
    return 0;
}
size_t get_ribbon(vector<size_t> v)
{
    sort(v.begin(),v.end());
    return get_bow(v)+get_wrap(v);
}
size_t get_bow(vector<size_t> v)
{
    return (v.at(0)*v.at(1)*v.at(2));
}
size_t get_wrap(vector<size_t> v)
{
    return (v.at(0)*2)+(v.at(1)*2);
}