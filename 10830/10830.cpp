#include <iostream>
#include <vector>

using namespace std;

struct Matrix {
    int m[6][6];
    int size;

    static Matrix identity(int size) {
        Matrix ret;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ret.m[i][j] = 1;
            }
        }

        return ret;
    }

    Matrix operator*(Matrix rhs) {
        Matrix ret;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ret.m[i][j] = 0;
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    ret.m[i][j] += this->m[i][k] * rhs.m[k][j];
                }

                ret.m[i][j] %= 1000;
            }
        }

        ret.size = this->size;

        return ret;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << this->m[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

Matrix square(Matrix m, long long sqr) {
    if (sqr == 0) return Matrix::identity(m.size);
    if (sqr == 1) {
        return m;
    }

    Matrix a = square(m, sqr / 2);
    if (sqr % 2 != 0) {
        return a * a * m;
    }  else {
        return a * a;
    }
}

int main() {
    int n;
    long long b;

    Matrix m;

    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m.m[i][j];
            m.m[i][j] %= 1000;
        }
    }

    m.size = n;

    Matrix ret = square(m, b);

    ret.print();

    return 0;
}