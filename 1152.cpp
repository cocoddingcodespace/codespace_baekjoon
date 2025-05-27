#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int i = 0, c = 0;

    getline(cin, s);

    while (i < s.size()) {
        while ((s[i] == ' ' || s[i] == '\n') && i < s.size()) i++;

        if (i == s.size()) break;

        c++;

        while (s[i] != ' ' && i < s.size()) i++;
    }

    cout << c << endl;
    
    return 0;
}