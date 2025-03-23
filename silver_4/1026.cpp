#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, res = 0;
    int a[50] = {0,};
    int b[50] = {0,};

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n, greater<int>());

    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }

    cout << res << endl;

    return 0;
}