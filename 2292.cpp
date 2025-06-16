#include <iostream>

using namespace std;

int main() {
    int n, i = 1, p = 1;

    cin >> n;

    while (p < n) {
        p += i * 6;
        i++;
    }

    cout << i << endl;

    return 0;
}