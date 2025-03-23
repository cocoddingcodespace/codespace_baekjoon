#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    vector<string> ss;

    cin >> s;

    for (int i = 1; i < s.size() - 1; i++) {
        for (int j = i; j < s.size() - 1; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i + 1);
            string c = s.substr(j + 1, s.size() - j);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            ss.push_back(a + b + c);
        }
    }

    sort(ss.begin(), ss.end());

    cout << ss[0] << endl;

    return 0;
}