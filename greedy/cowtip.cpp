#include <bits/stdc++.h>
using namespace std;

void flip(vector<string>& arr, int x, int y) {
    for (int i = 0 ; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (arr[i].at(j) == '0') arr[i].at(j) = '1';
            else arr[i].at(j) = '0';
        }
    }
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("cowtip.in");
    fout.open("cowtip.out");

    int n;
    fin >> n;

    vector<string> board;

    for (int i = 0; i < n; i++) {
        string s;
        fin >> s;
        board.push_back(s);
    }
    int num_flips = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (board[i].at(j) == '1') {
                flip(board, i, j);
                num_flips++;
            }
        }
    }

    fout << num_flips;
    fin.close();
    fout.close();
    return 0;
}