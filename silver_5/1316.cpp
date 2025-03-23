#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, cnt = 0;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        int len = 0;
        bool visit[27] = {false,};

        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            int idx = c - 97;

            if (!visit[idx] || (j > 0 && s[j - 1] == c)) {
                len++;
                visit[idx] = true;
            }
        }

        if (len == s.size()) cnt++;
    }

    cout << cnt << endl;

    return 0;
}