#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin;
    ofstream fout;
    fin.open("shell.in");
    int n;
    fin >> n;
    int game[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            fin >> game[i][j];
        }
    }
    int max_score = 0;

    for (int i = 1; i <= 3; i++) {
        int rock_position = i;
        int score = 0;
        for (int j = 0; j < n; j++) {
            if (game[j][0] == rock_position) {
                rock_position = game[j][1];
            }
            else if (game[j][1] == rock_position) {
                rock_position = game[j][0];
            }
            if (game[j][2] == rock_position) {
                score++;
            }
        }
        max_score = max(max_score, score);
    }
    fout.open("shell.out");
    fout << max_score << endl;

    fin.close();
    fout.close();
    return 0;
}