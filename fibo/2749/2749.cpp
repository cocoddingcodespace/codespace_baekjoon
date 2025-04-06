#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long >> Matrix;

Matrix multiply(Matrix a, Matrix b) {
    int n = a.size();
    int m = a[0].size();

    Matrix ret;

    for (int i = 0; i < n; i++) {
        ret.push_back(vector<long long>());

        for (int j = 0; j < m; j++) {
            ret[i].push_back(0);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long  sum = 0;

            for (int k = 0; k < m; k++) {
                sum += a[i][k] * b[k][j];
                sum %= 1000000;
            }

            ret[i][j] = sum;
        }
    }

    return ret;
}

Matrix pow(Matrix m, long long sqr) {
    if (sqr == 0 || sqr == 1) return m;

    Matrix ret = pow(m, sqr / 2);
    if (sqr % 2 == 1) {
        return multiply(multiply(ret, ret), m);
    }
    
    return multiply(ret, ret);
}

int main() {
    long long n;

    cin >> n;

    Matrix a = {
        {0, 1},
        {1, 1}
    };

    Matrix ret = pow(a, n - 1);

    cout << ret[1][1] << endl;

    return 0;
}