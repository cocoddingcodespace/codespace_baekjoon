#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Vector2;
void find_cluster(Vector2, int[][101], int);
int calculate_height(Vector2, int[][101]);

int r, c, n, h;
char map[101][101];
bool is_right;

struct Vector2 {
    int x, y;
};

struct Compare {
    bool operator()(const Vector2& lhs, const Vector2& rhs) {
        return lhs.y < rhs.y;
    }
};

const Vector2 none = {-1, -1};
Vector2 direction[4] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

Vector2 throw_stick(int h, bool is_right) {
    for (int i = 0; i < c; i++) {
        int x = is_right ? c - i - 1 : i;

        if (map[h][x] == 'x') return {x, h};
    }

    return none;
}

void broke_mineral(Vector2 pos) {
    int group[101][101] = {0, };
    int group_size = 1;

    map[pos.y][pos.x] = '.';

    for (int i = 0; i < 4; i++) {
        Vector2 next = {pos.x + direction[i].x, pos.y + direction[i].y};

        if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r) continue;
        if (map[next.y][next.x] == '.') continue;
        if (group[next.y][next.x] != 0) continue;

        find_cluster(next, group, group_size++);
    }
}

void find_cluster(Vector2 pos, int (*group)[101], int group_number) {
    queue<Vector2> q;
    priority_queue<Vector2, vector<Vector2>, Compare> pq;

    q.push(pos);

    while(!q.empty()) {
        Vector2 cur = q.front();
        q.pop();

        if (group[cur.y][cur.x] != 0) continue;
        if (map[cur.y][cur.x] == '.') continue;

        group[cur.y][cur.x] = group_number;

        pq.push(cur);

        for (int i = 0; i < 4; i++) {
            Vector2 next = {cur.x + direction[i].x, cur.y + direction[i].y};

            if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r) continue;

            q.push(next);
        }
    }

    if (pq.size() > 0 && pq.top().y != r - 1) {
        int moveY = 101;
        Vector2 lt = {101, 101};
        Vector2 rb = {0, 0};

        while(!pq.empty()) {
            Vector2 cur = pq.top();
            pq.pop();

            lt.x = min(cur.x, lt.x);
            lt.y = min(cur.y, lt.y);
            rb.x = max(cur.x, rb.x);
            rb.y = max(cur.y, rb.y);

            if (cur.y + 1 < r && map[cur.y + 1][cur.x] == '.') {
                moveY = min(moveY, calculate_height(cur, group));
            }
        }

        for (int y = rb.y; y >= lt.y; y--) {
            for (int x = rb.x; x >= lt.x; x--) {
                if (map[y][x] == '.' || group[y][x] != group_number) continue;
                map[y + moveY][x] = map[y][x];
                map[y][x] = '.';
            }
        }
    }
}

int calculate_height(Vector2 pos, int (*group)[101]) {
    int g = group[pos.y][pos.x];
    int ny = pos.y + 1;

    while ((map[ny][pos.x] == '.' && ny < r) || group[ny][pos.x] == g) { 
        ny++;
    }

    return ny - pos.y - 1;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h;

        Vector2 broken_point = throw_stick(r - h, is_right);
        is_right = !is_right;

        if (broken_point.x == -1 && broken_point.y == -1) continue;

        broke_mineral(broken_point);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}