#include <iostream>

using namespace std;

int main() {
    int n, m = 0;
    int arr[1001];
    int asend_dp[1001];
    int desend_dp[1001];

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        asend_dp[i] = desend_dp[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j]) {
                asend_dp[i] = max(asend_dp[j] + 1, asend_dp[i]);
            }
        }

        for (int j = n - i + 1; j <= n; j++) {
            if (arr[n - i] > arr[j]) {
                desend_dp[n - i] = max(desend_dp[j] + 1, desend_dp[n - i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        m = max(m, asend_dp[i] + desend_dp[i] - 1);
    }

    cout << m << endl;

    return 0;
}