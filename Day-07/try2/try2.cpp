#include <bits/stdc++.h>

using namespace std;
// string Path = "..//example copy.txt";
string Path = "..//input-part2.txt";

map<string, unsigned short> val;
map<string, unsigned short> val2;
vector<string> li;
vector<int> indexlist;

bool findTo(string towards)
{
    auto it = val.find(towards);
    if (it != val.end())
    {
        cout << "Double source\n";
        return false;
    }
    else
    {
        return true;
    }
}
bool findOR(string a, string b, string towards)
{
    auto it1 = val.find(a);
    auto it2 = val.find(b);
    if ((it1 != val.end()) && (it2 != val.end()))
    {
        cout << "second " << val[a] << " " << val[b];
        val2[towards] = (val[a] | val[b]);
        return true;
    }
    return false;
}
bool findAnd(string a, string b, string towards)
{
    if (isdigit(a.at(0)))
    {
        auto it = val.find(b);
        if (it != val.end())
        {

            val2[towards] = (stoi(a, nullptr, 10) & val[b]);
            // cout << "found And leading 1\n";
            return true;
        }
        return false;
    }
    else
    {
        auto it1 = val.find(a);
        auto it2 = val.find(b);
        if ((it1 != val.end()) && (it2 != val.end()))
        {
            // cout << "second " << val[a] << " " << val[b];
            val2[towards] = (val[a] & val[b]);
            return true;
        }
        return false;
    }
}

void loop()
{
    for (size_t i = 0; i < li.size(); i++)
    {
        cout << i << ": " << li.at(i) << '\t';
        stringstream finder{li.at(i)};
        string first, second, incase;
        string to;
        finder >> first;
        finder >> incase;
        if (first == "NOT")
        {
            auto it = val.find(incase);
            if (it != val.end())
            {
                finder.ignore(3);
                finder >> to;
                if (findTo(to))
                {
                    val2[to] = ~val[incase];
                    indexlist.push_back(i);
                }
            }
        }
        else if (incase == "AND")
        {
            finder >> second;
            finder.ignore(3);
            finder >> to;
            if (findTo(to))
            {

                if (findAnd(first, second, to))
                {
                    indexlist.push_back(i);
                    // cout << first << " " << incase << " " << second << " " << to << " " << val2[to] << endl;
                }
            }
        }
        else if (incase == "OR")
        {
            finder >> second;
            finder.ignore(3);
            finder >> to;
            if (findTo(to))
            {

                if (findOR(first, second, to))
                {
                    indexlist.push_back(i);
                    // cout << first << " " << incase << " " << second << " " << to << " " << val2[to] << endl;
                }
            }
        }
        else if (incase == "RSHIFT")
        {
            auto it = val.find(first);
            if (it != val.end())
            {
                finder >> second;
                finder.ignore(3);
                finder >> to;
                if (findTo(to))
                {

                    val2[to] = (val[first] >> stoi(second, nullptr, 10));
                    // cout << (val[first] >> stoi(second, nullptr, 10)) << endl;
                    indexlist.push_back(i);
                }
            }
        }
        else if (incase == "LSHIFT")
        {
            auto it = val.find(first);
            if (it != val.end())
            {
                finder >> second;
                finder.ignore(3);
                finder >> to;
                if (findTo(to))
                {

                    val2[to] = (val[first] << stoi(second, nullptr, 10));
                    indexlist.push_back(i);
                    // cout << first << " " << incase << " " << second << " " << to << " " << val2[to] << endl;
                }
            }
        }
        else if (incase == "->")
        {
            auto it = val.find(first);
            if (it != val.end())
            {
                cout << first << endl;
                finder >> to;
                if (findTo(to))
                {

                    val2[to] = val[first];
                    indexlist.push_back(i);
                }
            }
        }
        else
        {
            cout << "error\n";
            cout << first << " " << incase << endl;
            break;
        }

        cout << endl;
    }
    sort(indexlist.rbegin(), indexlist.rend());
    for (auto &&i : indexlist)
    {
        cout << li.at(i) << endl;
        li.erase(li.begin() + i);
    }

    cout << endl;
    val.insert(val2.begin(), val2.end());
    val2.clear();
    indexlist.clear();
}

int main()
{
    ifstream input{Path};
    string l;
    while (getline(input, l))
    {
        stringstream parser{l};
        string first, second, arrow;
        parser >> first;
        parser >> arrow;
        parser >> second;
        if (arrow == "->" && isdigit(first.at(0)))
        {
            val[second] = stoi(first, nullptr, 10);
        }
        else
        {
            li.push_back(l);
        }
    }

    for (size_t i = 0; i < 1000; i++)
    {
        auto it = val.find("a");
        if (it != val.end())
        {
            cout << "found\n";
            break;
        }
        loop();
    }

    for (auto &&i : val)
    {
        cout << "val: " << i.first << '\t' << i.second << endl;
    }
    return 0;
}
