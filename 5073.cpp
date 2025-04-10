#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    while(true) {
        int arr[3];

        for (int i = 0; i < 3; i++) {
            cin >> arr[i];
        }

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;

        sort(arr, arr + 3);

        if (arr[0] + arr[1] <= arr[2]) {
            cout << "Invalid" << endl;
            continue;
        }

        if (arr[0] + arr[1] + arr[2] == arr[0] * 3) {
            cout << "Equilateral" << endl;
        } else if (arr[0] == arr[1] || arr[1] == arr[2]) {
            cout << "Isosceles" << endl;
        } else {
            cout << "Scalene" << endl;
        }
    }
    return 0;
}