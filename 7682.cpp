#include <iostream>
#include <string>

using namespace std;

int t[8][9] = {
    { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
    { 1, 0, 0, 1, 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 1, 0, 1, 0, 0 }
};

bool check_winner(string& board, char type) {
    for (int i = 0; i < 8; i++) {
        int w = 0;

        for (int j = 0; j < 9; j++) {
            if (t[i][j]) {
                if (type == board[j]) w++;
            }
        }

        if (w == 3) return true;
    }

    return false;
}

int main() {
    while (true) {
        int x, o, blank;
        x = o = blank = 0;

        string board;

        cin >> board;

        if (board == "end") break;

        for (int i = 0; i < 9; i++) {
            if (board[i] == 'X') x++;
            else if (board[i] == 'O') o++;
            else blank++;
        }

        // 1. x를 무조건 첫 수에 두기 때문에 o가 x보다 많을 수 없다. 
        if (o > x) {
            cout << "invalid" << endl;
            continue;
        }

        // x와 o의 차이는 1 보다 클 수 없다.
        if (abs(x - o) > 1) {
            cout << "invalid" << endl;
            continue;
        }

        bool x_win = check_winner(board, 'X');
        bool o_win = check_winner(board, 'O');

        if (o_win && !x_win) {
            if (o < x) {
                cout << "invalid" << endl;
            } else {
                cout << "valid" << endl;
            }
            continue;
        }

        if (x_win && !o_win) {
            // X가 이겼을 경우 O는 X보다 수를 한 수 덜 둔다.
            if (o >= x) {
                cout << "invalid" << endl;
            } else {
                cout << "valid" << endl;
            }
            continue;
        }

        if (o_win && x_win) {
            cout << "invalid" << endl;
            continue;
        }

        if (blank == 0 && !x_win && !o_win) {
            // 무승부일 경우 가능하다.
            cout << "valid" << endl;
            continue;
        } else {
            // 게임이 아직 종료되지 않았을 경우 최종상태가 아니다.
            cout << "invalid" << endl;
            continue;
        }
    }

    return 0;
}