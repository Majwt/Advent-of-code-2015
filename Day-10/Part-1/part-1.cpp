#include <bits/stdc++.h>

using namespace std;

class part1
{
private:
    vector<pair<char, int>> numberC;
    string _input;
    string _working;

public:
    part1(string input);
    void fillmap();
    void makeChange();
    void print();
};

part1::part1(string input)
{
    _input = input;
    _working = input;
}
void part1::print()
{
    cout << _input << endl;
    cout << _input.size() << endl;
    // for (auto &&i : numberC)
    // {
    //     cout << i.first << ":\t" << i.second << endl;
    // }
}
void part1::fillmap()
{
    numberC.clear();
    vector<char> chartrack = {_input.at(0)};
    vector<int> counter = {1};
    for (int i = 1, j = 0, c = 0; i < _input.size(); i++)
    {

        if (_input.at(i) != chartrack.at(j))
        {
            chartrack.push_back(_input.at(i));
            counter.push_back(1);
            c = 0;
            j++;
        }
        else
        {
            counter.at(j)++;
        }
    }
    try
    {
        for (size_t i = 0; i < counter.size(); i++)
        {
            pair<char, int> temp;
            temp.first = chartrack.at(i);
            temp.second = counter.at(i);

            numberC.push_back(temp);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n'
                  << chartrack.size() << " != " << counter.size() << '\n';
    }
}
void part1::makeChange()
{
    _working = "";
    for (auto &&i : numberC)
    {
        string leading = to_string(i.second);

        _working += leading;
        for (size_t j = 0; j < 1; j++)
        {
            _working += i.first;
        }
    }
    _input = _working;
}

int main()
{
    part1 obj("3113322113");
    // part1 obj("1");
    obj.print();
    for (size_t i = 0; i < 50; i++)
    {

        cout << endl;
        obj.fillmap();
        obj.print();
        obj.makeChange();
    }
    cout << endl;
    obj.print();
    

    return 0;
}
