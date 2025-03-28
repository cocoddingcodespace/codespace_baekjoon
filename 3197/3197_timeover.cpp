// 답은 맞지만 시간 초과....
#include <iostream>
#include <queue>

using namespace std;

int r, c;
char map[1501][1501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> next_melt;

bool is_met(pair<int, int> pos) {
    bool visit[1501][1501] = {false, };
    queue<pair<int, int>> q;

    int sx = pos.first;
    int sy = pos.second;

    visit[sx][sy] = true;

    for (int i = 0; i < 4; i++) {
        q.push({sx + dx[i], sy + dy[i]});
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x < 0 || x >= r || y < 0 || y >= c)  continue;

        if (visit[x][y]) continue;
        if (map[x][y] == 'L') return true;

        visit[x][y] = true;

        // 다음에 녹일 얼음 저장
        if (map[x][y] == 'X') {
            next_melt.push({x, y});
            continue;
        }

        for (int i = 0; i < 4; i++) {
            q.push({x + dx[i], y + dy[i]});
        }
    }

    return false;
}

void melt() {
    while(!next_melt.empty()) {
        int x = next_melt.front().first;
        int y = next_melt.front().second;

        next_melt.pop();

        map[x][y] = '.';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> swans[2];
    int sc = 0;
    int date = 0;

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];

            // 백조 위치 좌표 저장
            if (map[i][j] == 'L') {
                swans[sc++] = {i, j};
            }
        }
    }

    // 백조가 서로 만날 수 있는 지 확인
    while(!is_met(swans[0]) && !is_met(swans[1])) {
        // 만날 수 없으면 날짜가 지남
        date++;

        // 얼음 녹이기
        melt();
    }

    cout << date << endl;

    return 0;
}