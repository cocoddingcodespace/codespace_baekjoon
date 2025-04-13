#include <iostream>

using namespace std;

int n;
int w[16][16];
int s[16][16][16];
bool visit[16];

int tsp(int cur, int cost, int depth) {
    if (depth == n) {
        return cost;
    }

    int ret = INT32_MAX;

    for (int i = 0; i < n; i++) {
        if (visit[i] || i == cur) continue;
        if (w[cur][i] == 0) continue;

        visit[i] = true;

        int next_cost = cost + w[cur][i];

        if (s[depth][cur][i] > next_cost) {
            s[depth][cur][i] = next_cost;

            ret = min(ret, tsp(i, next_cost, depth + 1));
        }

        visit[i] = false;
    }

    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];

            for (int k = 0; k < n; k++) {
                s[k][i][j] = INT32_MAX;
            }
        }
    }

    cout << tsp(0, 0, 0) << endl;

    return 0;
}