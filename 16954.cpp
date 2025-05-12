#include <iostream>
#include <vector>

using namespace std;

struct Vector {
    int x, y;
};

Vector directions[9] = {
    {0, 0},
    {1, 0},
    {1, 1},
    {1, -1},
    {-1, 0},
    {-1, 1},
    {-1, -1},
    {0, 1},
    {0, -1}
};

bool is_remain_walls(vector<vector<char>>& field) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[7 - i][j] == '#') return true;
        }
    }

    return false;
}

bool is_alive(vector<vector<char>>& field, Vector pos) {
    return field[pos.y][pos.x] == '.';
}

void move_wall(vector<vector<char>>& field) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            field[7 - i][j] = field[7 - i - 1][j];
        }
    }

    for (int i = 0; i < 8; i++) {
        field[0][i] = '.';
    }
}

int solution(vector<vector<char>> field, Vector pos, bool is_wall_move = true) {
    if (is_wall_move) move_wall(field);

    if (!is_alive(field, pos)) return 0;
    if (!is_remain_walls(field)) 
        return 1;

    int ret = 0;

    for (int i = 0; i < 9; i++) {
        Vector next = {pos.x + directions[i].x, pos.y + directions[i].y};

        if (next.x < 0 || next.y < 0 || next.x >= 8 || next.y >= 8) continue;
        if (field[next.y][next.x] == '#') continue;
        if (!is_alive(field, next)) continue;

        ret |= solution(field, next);
    }

    return ret;
}

int main() {
    vector<vector<char>> field(8, vector<char>(8, ' '));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> field[i][j];
        }
    }

    int ret = solution(field, {0, 7}, false);

    cout << ret << endl;

    return 0;
} 