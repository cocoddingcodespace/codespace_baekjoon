#include <iostream>

using namespace std;

int main() {
    int x;
    int level = 1;

    cin >> x;

    while(x > level * (level + 1) / 2) {
        level++;
    }

    int idx = (level) * (level + 1) / 2 - x;
    int r = idx + 1;
    int l = level - idx;

    if (level % 2 == 1) {
        cout << r << '/' << l << endl;
    } else {
        cout << l << '/' << r << endl;
    }

    return 0;
}