#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int a[26];
    int m = 0;

    cin >> s;

    fill(a, a + 26, 0);

    for (char c : s) {
        int k = (int) c;
        if (k >= 97) k -= 32;

        a[k - 65]++;

        if (a[m] < a[k-65]) m = k - 65;
    }

    sort(a, a + 26, greater<int>());

    if (s.size() > 1 && a[0] == a[1]) cout << '?' << endl;
    else cout << (char) (m + 65) << endl;

    return 0;
}