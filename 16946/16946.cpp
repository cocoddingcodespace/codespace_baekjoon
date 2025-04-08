#include <iostream>
#include <vector> 
#include <set>

using namespace std;

int n, m, rank_size = 0;
int r[1001][1001];
int blank[1000001] = {0, };
char map[1001][1001];
vector<pair<int, int>> walls;

// 이동 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void bfs(int x, int y, int& sum) {
    if (r[x][y] != 0) return;

    r[x][y] = rank_size;
    sum++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dirX[i];
        int ny = y + dirY[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (map[nx][ny] == '1') continue;
        if (r[nx][ny] != 0) continue;

        bfs(nx, ny, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            r[i][j] = 0;    // 방문 안한 노드 표시
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (r[i][j] != 0) continue;
            if (map[i][j] == '1') {
                walls.push_back({i, j});
                continue;
            }

            rank_size++;

            int sum = 0;
            bfs(i, j, sum);

            blank[rank_size] = sum;
        }
    }

    int ret[1001][1001] = { 0, };

    for (pair<int, int> w : walls) {
        set<int> s;

        for (int i = 0; i < 4; i++) {
            int x = w.first + dirX[i];
            int y = w.second + dirY[i];

            if (x < 0 || x >= n || y < 0 || y >= m) continue;

            s.insert(r[x][y]);
        }

        int sum = 0;
        for (int t : s) {
            sum += blank[t];
        }

        ret[w.first][w.second] = (sum + 1) % 10;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ret[i][j];
        }
        cout << '\n';
    }

    return 0;
}