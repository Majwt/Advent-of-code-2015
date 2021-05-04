#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream input{"..//input.txt"};
    string l;
    getline(input,l);
    cout << l << endl;
    int counter,indexC = 0;
    for (auto &&i : l)
    {
        indexC++;
        if (i == '(') {
            counter++;
        } else {
            counter--;
        }
        if (counter == -1) {
            break;
        }
    }
    cout << indexC;
    return 0;
}