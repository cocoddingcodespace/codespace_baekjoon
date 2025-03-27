#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, size = 0;

    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;

    // 형태
    // 최대힙 <-> 최소힙
    // 중간값은 최대 힙과 최소 힙 사이의 값
    // maxq의 top 값은 항상 minq의 top보다 작다.

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;

        cin >> m;

        if (size == 0) {
            maxq.push(m);
        } else if (size == 1) { 
            if (m > maxq.top()) {
                minq.push(m);
            } else {
                minq.push(maxq.top());
                maxq.pop();
                maxq.push(m);
            }
        } else {
            maxq.push(m);

            if (maxq.top() > minq.top()) {
                minq.push(maxq.top());
                maxq.pop();

                if (minq.size() > maxq.size()) {
                    maxq.push(minq.top());
                    minq.pop();
                }
            }

            if (maxq.size() - minq.size() > 1) {
                minq.push(maxq.top());
                maxq.pop();
            }
        }

        // endl 보단 \n가 속도가 더 빠르다............
        // 문제가 계속 틀렸던 이유.......
        cout << maxq.top() << '\n';

        size++;
    }

    return 0;
}