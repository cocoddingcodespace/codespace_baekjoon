#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
long long f[4000001];

long long pow(int n, long long sqr) {
    if (sqr == 0) return 1 % MOD;
    if (sqr == 1) return n % MOD;

    long long q = pow(n, sqr / 2);
    if (sqr % 2 == 1) {
        return ((q * q) % MOD * n % MOD);
    }

    return (q * q) % MOD;
}

void fac() {
    f[0] = 1;

    for (int i = 1; i <= 4000000; i++) {
        f[i] = f[i - 1] * i % MOD;
    }
}

int main() {
    int n, k;

    cin >> n >> k;

    fac();

    long long ret = ((f[n] * pow(f[k], MOD - 2)) % MOD) * pow(f[n - k], MOD - 2) % MOD;

    cout << ret << endl;

    return 0;
}