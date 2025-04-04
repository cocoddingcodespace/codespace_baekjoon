#include <iostream>
#include <vector>

using namespace std;

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
char map[21][21];
int w, h;

bool checkExist(pair<int, int> pos, vector<pair<int, int>> v) {
    for (int i = 0; i < v.size(); i++) {
        if (pos == v[i]) {
            return true;
        }
    }

    return false;
}

int findShortestRoute(pair<int, int> pos, int dirtyCount, int depth, vector<pair<int, int>> s) {
    if (depth >= w * h) return -1;
    if (dirtyCount == 0) return depth;

    int ret = 20 * 20 + 1;

    for (int i = 0; i < 4; i++) {
        int nx = pos.first + dirX[i];
        int ny = pos.second + dirY[i];
        pair<int, int> npos = {nx, ny};

        if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
            continue;
        }
        if (map[nx][ny] == 'x') {
            continue;
        }
        if (map[nx][ny] == '*') {
            if (!checkExist(npos, s)) {
                dirtyCount--;
                s.push_back(npos);
            }
        }

        depth++;
        
        ret = min(ret, findShortestRoute(npos, dirtyCount, depth, s));
    }

    return ret;
}

int main() {
    while(true) {
        int dirtyCount = 0;
        pair<int, int> start;

        cin >> w >> h;

        if (w == 0 && h == 0) break;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> map[i][j];

                if (map[i][j] == '*') dirtyCount++;
                else if (map[i][j] == 'o') start = {i, j};
            }
        }

        int ret = findShortestRoute(start, dirtyCount, 0, vector<pair<int, int>>());

        cout << "result : " << ret << endl;
    }
    
    return 0;
}