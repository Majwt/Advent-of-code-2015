#include <bits/stdc++.h>

using namespace std;
string path = "..//input.txt";
// string path = "..//example.txt";

char asiic_c(string asiic)
{
    string part = asiic.substr(2);
    char ch = stoul(part, nullptr, 16);
    return ch;
}
string loop(string l)
{
    int len = l.size();
    string fin = "";
    string characters = l.substr(1, len - 1);
    for (size_t i = 0; i < len-2; i++)
    {
        if (characters.at(i) == '\\')
        {
            if (characters.at(i+1) == '\\') {

                fin += '\\';
                i+=1;
                continue;
            }
            else if (i + 3 < len)
            {
                if ((characters.at(i + 1) == 'x') ) // && ((isdigit(characters.at(i + 2))) && (isdigit(characters.at(i + 3))))
                {
                    fin += asiic_c(characters.substr(i, 4));
                    i+= 3;
                    continue;
                }
                else {
                fin += characters.at(i + 1);
                i+=1;

                }
            }
            else
            {
                fin += characters.at(i + 1);
                i+=1;
                continue;
            }
        }
        else {
            fin += characters.at(i);
        }
    }
    return fin;
}
int main()
{
    vector<int> s_lenght, c_lenght;

    ifstream input{path};
    string l;
    while (getline(input, l))
    {
        cout << "code Length:\t" << l.size() << "\t";
        cout << l << endl;
        c_lenght.push_back(l.size());
        string s = loop(l);
        s_lenght.push_back(s.size());
        cout << "string Length:\t" << s.size() << "\t";
        cout << s << endl;
    }
    int s_sum,c_sum = 0;
    for (size_t i = 0; i < s_lenght.size(); i++)
    {
        s_sum += s_lenght.at(i);
        c_sum += c_lenght.at(i);
    }
    cout << c_sum << " - " << s_sum << " = " << c_sum-s_sum << endl;
    return 0;
}
