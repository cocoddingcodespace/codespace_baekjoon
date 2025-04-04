#define INF 401
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct NODE {
    int x, y, depth = 0;

    bool operator<(const NODE& rhs) const {
        return this->depth < rhs.depth;
    }
};

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int dist[401][21][21];

void initialize(int (*dist)[21], int sx, int sy) {
    for (int y = 0; y < sy; y++) {
        for (int x = 0; x < sx; x++) {
            dist[y][x] = INF;
        }
    }
}

void findShortestRoute(char (*room)[21], int (*dist)[21], NODE start, int w, int h) {
    priority_queue<NODE> q;

    dist[start.y][start.x] = 0;
    q.push(start);

    while(!q.empty()) {
        NODE c = q.top();

        q.pop();

        for (int i = 0; i < 4; i++) {
            NODE next = {c.x + dirX[i], c.y + dirY[i], c.depth + 1};

            if (next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
            if (room[next.y][next.x] == 'x') continue;

            if (dist[next.y][next.x] > next.depth) {
                dist[next.y][next.x] = next.depth;

                q.push(next);
            }
        }
    }
}

bool visit[401];
int arr[401];

int getOptimizeRoute(vector<NODE> places, int depth) {
    int n = places.size();

    if (n == depth) {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int c = arr[i];
            int ni = arr[i + 1];

            NODE next = places[ni];

            int d = dist[c][next.y][next.x];

            if (d == INF) return -1;

            sum += d;
        }

        return sum;
    }
    
    int ret = 401 * 401 + 1;

    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;
        visit[i] = true;

        arr[depth] = i;

        ret = min(ret, getOptimizeRoute(places, depth + 1));

        visit[i] = false;
    }

    return ret;
}

int main() {
    while(true) {
        int w, h;

        cin >> w >> h;

        if (w == 0 && h == 0) break;

        char room[21][21];
        int placeCount = 0;

        vector<NODE> places;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> room[i][j];

                if (room[i][j] == 'o' || room[i][j] == '*') {
                    places.push_back({j, i});

                    initialize(dist[placeCount++], w, h);
                }
            }
        }

        for (int i = 0; i < placeCount; i++) {
            findShortestRoute(room, dist[i], places[i], w, h);
        }

        cout << getOptimizeRoute(places, 0) << endl;
    }

    return 0;
}