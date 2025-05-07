#include <iostream>

using namespace std;

int town[3][1001];
int dp[3][3][1001];

int main() {
    int n, res = 1000 * 1000 + 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> town[0][i] >> town[1][i] >> town[2][i];
    }

    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 3; i++) {
            dp[c][i][0] = town[c][0];
        }

        for (int i = 1; i <= n; i++) {
            dp[c][0][i] = town[0][i] + min(dp[c][1][i - 1], dp[c][2][i - 1]);
            dp[c][1][i] = town[1][i] + min(dp[c][0][i - 1], dp[c][2][i - 1]);
            dp[c][2][i] = town[2][i] + min(dp[c][0][i - 1], dp[c][1][i - 1]);

            if (i == 1) dp[c][c][i] = 1000 * 1000 + 1;
        }

        for (int j = 0; j < 3; j++) {
            if (c == j) continue;
            res = min(dp[c][j][n - 1], res);

        }
    }

    cout << res << endl;

    return 0;
}