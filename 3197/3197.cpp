#define INF 3000000
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int r, c;
char map[1501][1501] = {0,};
int lake[1501][1501] = {0,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> swans[2];

struct NODE {
    int x, y;
    int depth;

    bool operator<(const NODE& lhs) {
        return this->depth < lhs.depth;
    }
};

queue<NODE> q;

void solution() {
    bool visit[1501][1501] = {false};

    while(!q.empty()) {
        NODE cur = q.front();

        q.pop();

        for (int i = 0; i < 4; i++) {
            NODE next = {cur.x + dx[i], cur.y + dy[i], cur.depth};
            if (next.x >= r || next.x < 0 || next.y >= c || next.y < 0) continue;

            if (map[next.x][next.y] == 'X' && lake[next.x][next.y] > cur.depth + 1) {
                lake[next.x][next.y] = cur.depth + 1;
                next.depth++;

                q.push(next);
            } 
            else if (visit[next.x][next.y]) {
                lake[next.x][next.y] = min(lake[next.x][next.y], cur.depth);
            }
            else if (map[next.x][next.y] != 'X' && !visit[next.x][next.y]) {
                visit[next.x][next.y] = true;
                lake[next.x][next.y] = cur.depth;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sidx = 0;

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'L') {
                swans[sidx++] = {i, j};
            }

            if (map[i][j] == '.') {
                q.push({i, j, 0});
            }

            if (map[i][j] == 'X') {
                lake[i][j] = INF;
            }
        }
    }

    q.push({swans[0].first, swans[0].second, 0});

    solution();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << lake[i][j] << ' ';
        }

        cout << endl;
    }
    
    // int result = ceil(lake[swans[1].first][swans[1].second] / 2.0f);
    // cout << "result : " << result << endl;
    // cout << result << endl;

    return 0;
}