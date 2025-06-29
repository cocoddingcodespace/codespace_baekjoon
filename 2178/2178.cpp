#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n, m;
char maze[101][101];

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

struct TILE {
    int x, y, depth;
};

int bfs() {
    bool cache[101][101] = {false,};

    queue<TILE> q;

    q.push({0, 0, 0});

    while (!q.empty()) {
        TILE cur = q.front();

        q.pop();

        if (maze[cur.y][cur.x] == '0') continue;
        if (cache[cur.y][cur.x]) continue;

        if (cur.y == n - 1 && cur.x == m - 1) {
            return cur.depth;
        }

        cache[cur.y][cur.x] = true;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dirX[i];
            int ny = cur.y + dirY[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (cache[ny][nx]) continue;

            q.push({nx, ny, cur.depth + 1});
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    cout << bfs() + 1 << endl;

    return 0;
}