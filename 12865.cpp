#include <iostream>

using namespace std;

int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int w, v;

        cin >> w >> v;

        for (int j = 1; j <= k; j++) {
            if (j - w >= 0) {
                dp[i][j] = max(dp[i - 1][j], v + dp[i - 1][j - w]);
            } else {
                dp[i][j] = dp[i][w - 1];
            }

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}