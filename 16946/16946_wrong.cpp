#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m;
char map[1001][1001];
pair<int, int> parent[1001][1001];
int r[1001][1001];
int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};
queue<pair<int, int>> q;
vector<pair<int, int>> walls;

pair<int, int> find_parent(pair<int, int> a) {
    if (parent[a.first][a.second] == a) return a;
    return parent[a.first][a.second] = find_parent(parent[a.first][a.second]);
}

void make_union(pair<int, int> a, pair<int, int> b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a == b) return;
    if (a > b) swap(a, b);

    parent[b.first][b.second] = a;
    r[a.first][a.second] += r[b.first][b.second];
}

void bfs() {
    bool visit[1001][1001];

    while(!q.empty()) {
        pair<int, int> c = q.front();

        int x = c.first;
        int y = c.second;

        q.pop();

        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (map[x][y] == '1') continue;
        if (visit[x][y]) continue;

        visit[x][y] = true;

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {x + dirX[i], y + dirY[i]};

            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
            if (map[next.first][next.second] == '1') continue;

            make_union(c, next);

            q.push(next);
        }
    }
}

void solution() {
    int ret[1001][1001];

    for (int i = 0; i < walls.size(); i++) {
        set<pair<int, int>> s;

        int sum = 0;
        int x = walls[i].first;
        int y = walls[i].second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dirX[i];
            int ny = y + dirY[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            pair<int, int> leader = find_parent({nx, ny});

            if (s.find(leader) != s.end()) continue;

            s.insert(leader);

            sum += r[leader.first][leader.second];
        }

        ret[x][y] = (sum + 1) % 10;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ret[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == '1') {
                r[i][j] = 0;
                walls.push_back({i, j});
            }
            else {
                r[i][j] = 1;
                q.push({i, j});
            }

            parent[i][j] = {i, j};
        }
    }

    bfs();
    solution();

    return 0;
}