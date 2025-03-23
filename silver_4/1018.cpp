#include <iostream>

using namespace std;

char board[51][51];
int sx, sy;

int get_repaint(int x, int y) {
    int bc = 0, wc = 0;

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            // 0, 0이 W
            if (i % 2 == 0) {
                if (j % 2 == 0 && board[i][j] == 'W') wc++;
                if (j % 2 == 1 && board[i][j] == 'B') bc++;
            } else {
                if (j % 2 == 1 && board[i][j] == 'W') wc++;
                if (j % 2 == 0 && board[i][j] == 'B') bc++;
            }
        }
    }

    return min(64 - (bc + wc), 64 - (64 - bc - wc));
}

int main() {
    cin >> sx >> sy;

    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            cin >> board[i][j];
        }
    }

    int m = 2500;

    for (int i = 0; i <= sx - 8; i++) {
        for (int j = 0; j <= sy - 8; j++) {
            m = min(m, get_repaint(i, j));
        }
    }

    cout << m << endl;

    return 0;
}