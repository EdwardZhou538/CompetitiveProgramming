#include <bits/stdc++.h>

using namespace std;

int backtrack(vector<vector<int>>& board, int x, int y, int num_queens) {
    if (num_queens == 0) return 1;
    //printf("(%d, %d)\n", x, y);
    if (y == 8) return 0;
    bool cannot_place = false;
    //cout << 1 << endl;
    if (board[x][y] == 1) cannot_place = true;
    for (int i = 0; i < x; i++) {
        if (board[i][y] == 2) {
            cannot_place = true;
            break;
        }
    }
    //cout << 2 << endl;
    for (int i = 0; i < y; i++) {
        if (board[x][i] == 2) {
            cannot_place = true;
            break;
        }
    }
    //cout << 3 << endl;
    int diag_x = x - 1;
    int diag_y = y - 1;

    while (diag_x >= 0 && diag_y >= 0) {
        if (board[diag_x][diag_y] == 2) {
            cannot_place = true;
            break;
        }
        diag_x--;
        diag_y--;
    }
    //cout << 4 << endl;

    diag_x = x + 1;
    diag_y = y - 1;
    while (diag_x < 8 && diag_y >= 0) {
        if (board[diag_x][diag_y] == 2) {
            cannot_place = true;
            break;
        }
        diag_x++;
        diag_y--;
    }
    //cout << 5 << endl;

    if (cannot_place) {
        if (x == 7) {
            //cout << "Cock??" << endl;
            return backtrack(board, 0, y+1, num_queens);
        }
        else return backtrack(board, x+1, y, num_queens);
    }

    board[x][y] = 2;
    int with_queen = 0;
    if (x == 7) {
        //cout << "HYPERBreuh" << endl;
        with_queen = backtrack(board, 0, y+1, num_queens-1);
    }
    else with_queen = backtrack(board, x+1, y, num_queens-1);

    board[x][y] = 0;
    int without_queen = 0;
    if (x == 7) {
        //cout << "Breuh" << endl;
        without_queen = backtrack(board, 0, y+1, num_queens);
    }
    else without_queen = backtrack(board, x+1, y, num_queens);

    return with_queen + without_queen;
}

int main() {
    //freopen("chess.in", "r", stdin);

    vector<vector<int>> board;

    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        vector<int> something;

        for (int j = 0; j < 8; j++) {
            if (s.at(j) == '.') something.push_back(0);
            else something.push_back(1);
        }
        board.push_back(something);
    }
    cout << backtrack(board, 0, 0, 8);
}