#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    pair<int, int> arr[51];
    int ret[51];

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        arr[i] = {tmp, i};
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int num = arr[i].first;
        int idx = arr[i].second;

        ret[idx] = i;
    }

    for (int i = 0; i < n; i ++) {
        cout << ret[i] << ' ';
    }
    cout << endl;

    return 0;
}