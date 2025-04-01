#define INF 100 * 100 + 1
#include <iostream>

using namespace std;

int main() {
    int n, m, sum = 0, result = INF;

    int memory[101];
    int cost[101];
    int dp[101][INF];

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> memory[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= n; i++) {
        int cm = memory[i];
        int c = cost[i];

        for (int j = 0; j <= sum; j++) {
            if (j - c >= 0) {
                dp[i][j] = max(dp[i - 1][j], cm + dp[i - 1][j - c]);
            } else {
                dp[i][j] = dp[i][j - 1];
            }

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            if (dp[i][j] >= m) {
                result = min(j, result);
                break;
            }
        }

    }

    cout << result << endl;
} 