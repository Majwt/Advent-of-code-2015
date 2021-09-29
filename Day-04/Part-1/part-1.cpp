#include <bits/stdc++.h>
#include "../md5/md5.h"
 
using std::cout; using std::endl; using std::string;
int part1(string key,int answer = 0) {
    bool not_found=true;
    while (not_found)
    {
        string input = key+std::to_string(answer);
        string hash = md5(input);
        if (hash.substr(0,5) == "00000") {
            not_found = false;
            break;
        }
        answer++;
    }
    return answer;
}

int part2(string key,int answer = 0) {
    bool not_found=true;
    while (not_found)
    {
        string input = key+std::to_string(answer);
        string hash = md5(input);
        if (hash.substr(0,6) == "000000") {
            not_found = false;
            break;
        }
        answer++;
    }
    return answer;
}

int main(int argc, char *argv[])
{
    // string key = "abcdef";
    string key = "ckczppom";
    int first = part1(key);
    cout << first << endl;
    cout << part2(key,first) << endl;
    return 0;
}
