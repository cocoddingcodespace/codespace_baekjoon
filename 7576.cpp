#include <iostream>
#include <queue>

using namespace std;

int n, m;
int ripe_cnt = 0, empty_cnt = 0;
int max_depth = 0;

int farm[1001][1001];
int ripe[1001][1001];

int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

struct NODE {
    int x, y, depth;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    queue<NODE> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> farm[i][j];

            if (farm[i][j] == 1) {
                q.push({j, i, 1});
            } else if (farm[i][j] == -1) {
                empty_cnt++;
            }
        }
    }

    while(!q.empty()) {
        NODE cur = q.front();

        q.pop();

        if (cur.x < 0 || cur.x >= n || cur.y < 0 || cur.y >= m) continue;
        if (ripe[cur.y][cur.x] > 0) continue;
        if (farm[cur.y][cur.x] == -1) continue;

        ripe[cur.y][cur.x] = cur.depth;
        ripe_cnt++;

        if (max_depth < cur.depth) max_depth = cur.depth;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dirX[i];
            int ny = cur.y + dirY[i];
            int nd = cur.depth + 1;

            if (ripe[ny][nx] > 0) continue;

            q.push({nx, ny, nd});
        }
    }

    if (n * m - empty_cnt != ripe_cnt) {
        cout << -1 << endl;
    } else {
        cout << max_depth - 1 << endl;
    }

    return 0;
}