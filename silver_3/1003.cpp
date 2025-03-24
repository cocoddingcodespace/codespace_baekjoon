#include <iostream>

using namespace std;

pair<int, int> fibo(int n) {
    pair<int, int> dp[41];

    dp[0] = {1, 0};
    dp[1] = {0, 1};
    dp[2] = {1, 1};

    for (int i = 2; i <= n; i++) {
        int a = dp[i - 1].first + dp[i - 2].first;
        int b = dp[i - 1].second + dp[i - 2].second;
        dp[i] = {a, b};
    }

    return dp[n];
}

int main() {
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        pair<int, int> ret = fibo(n);

        cout << ret.first << ' ' << ret.second << endl;
    }

    return 0;
}