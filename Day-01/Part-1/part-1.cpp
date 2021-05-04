#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream input{"..//input.txt"};
    string l;
    getline(input,l);
    cout << l << endl;
    int counter = 0;
    for (auto &&i : l)
    {
        if (i == '(') {
            counter++;
        } else {
            counter--;
        }
    }
    cout << counter;
    return 0;
}