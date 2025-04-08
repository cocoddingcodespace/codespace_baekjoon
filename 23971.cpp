#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float h, w;
    int n, m;

    cin >> h >> w >> n >> m;

    int a = ceil(h / (n + 1));
    int b = ceil(w / (m + 1));
    int ret = a * b;

    cout << ret << endl;

    return 0;
}