#include <iostream>

using namespace std;

int main() {
    int n, m = 0;
    int arr[1001];
    int dp[1001];

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        m = max(dp[i], m);
    }

    cout << m << endl;

    return 0;
}