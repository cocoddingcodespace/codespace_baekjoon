#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int bundle = 1001, each = 1001;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        bundle = min(bundle, a);
        each = min(each, b);
    }

    int ret = (n / 6) * bundle + (n % 6) * each;
    ret = min(ret, each * n);
    ret = min(ret, (n / 6 + 1) * bundle);

    cout << ret << endl;

    return 0;
}