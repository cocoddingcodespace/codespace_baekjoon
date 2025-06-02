#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int ss[27];

    cin >> s;

    fill(ss, ss + 26, -1);

    for (int i = 0; i < s.size(); i++) {
        int cur = (int) s[i] - 97;
        if (ss[cur] == -1) ss[cur] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << ss[i] << ' ';
    }

    return 0;
}