#define INF 987654321
#include <iostream>

using namespace std;

int n;
int w[16][16];
int dist[16][1 << 16] = {0,};

int tsp(int cur, int visit) {
    if (visit == (1 << n) - 1) {
        if (w[cur][0] == 0) return INF;
        return w[cur][0];
    }

    int& ret = dist[cur][visit];
    if (ret != 0) return ret;

    ret = INF;

    for (int next = 0; next < n; next++) {
        if (visit & (1 << next)) continue;
        if (w[cur][next] == 0) continue;

        int t = tsp(next, visit | (1 << next)) + w[cur][next];
        ret = min(ret, t);
    }

    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    cout << tsp(0, 1) << endl;

    return 0;
}