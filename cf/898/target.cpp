#include <bits/stdc++.h>

using namespace std;

void solve() {
    int score = 0;
    for (int i = 0; i < 10; i++) {
        string row; cin >> row;
        if (i == 0 || i == 9) {
            for (int j = 0; j < 10; j++) {
                if (row.at(j) == 'X') score++;
            }
        }

        if (i == 1 || i == 8) {
            if (row.at(0) == 'X') score++;
            if (row.at(9) == 'X') score++;
            for (int j = 1; j < 9; j++) {
                if (row.at(j) == 'X') score += 2;
            }
        }

        if (i == 2 || i == 7) {
            if (row.at(0) == 'X') score++;
            if (row.at(9) == 'X') score++;
            if (row.at(1) == 'X') score += 2;
            if (row.at(8) == 'X') score += 2;
            for (int j = 2; j < 8; j++) {
                if (row.at(j) == 'X') score += 3;
            }
        }
        if (i == 3 || i == 6) {
            if (row.at(0) == 'X') score++;
            if (row.at(9) == 'X') score++;
            if (row.at(1) == 'X') score += 2;
            if (row.at(8) == 'X') score += 2;
            if (row.at(2) == 'X') score += 3;
            if (row.at(7) == 'X') score += 3;
            for (int j = 3; j < 7; j++) {
                if (row.at(j) == 'X') score += 4;
            }
        }
        if (i == 4 || i == 5) {
            if (row.at(0) == 'X') score++;
            if (row.at(9) == 'X') score++;
            if (row.at(1) == 'X') score += 2;
            if (row.at(8) == 'X') score += 2;
            if (row.at(2) == 'X') score += 3;
            if (row.at(7) == 'X') score += 3;
            if (row.at(3) == 'X') score += 4;
            if (row.at(6) == 'X') score += 4;
            if (row.at(4) == 'X') score += 5;
            if (row.at(5) == 'X') score += 5;
        }
    }
    cout << score << endl;
}

int main() {
    //freopen("target.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}