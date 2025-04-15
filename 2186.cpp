#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n, m, k;
char tiles[101][101];
int dp[81][101][101] = { -1, };
string str;

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int dfs(int x, int y, int d) {
    if (dp[d][x][y] != -1) return dp[d][x][y];
    if (d + 1 == str.size()) return 1;

    int ret = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= k; j++) {
            int nx = x + dirX[i] * j;
            int ny = y + dirY[i] * j;

            if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
            if (tiles[nx][ny] != str[d + 1]) continue;

            ret += dfs(nx, ny, d + 1);
        }
    }

    dp[d][x][y] = ret;

    return ret;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tiles[i][j];
        }
    }

    cin >> str;

    memset(dp, -1, sizeof(dp));

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tiles[i][j] == str[0]) {
                ret += dfs(i, j, 0);
            }
        }
    }

    cout << ret << endl;

    return 0;
}