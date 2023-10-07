#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("hps.in");
    fout.open("hps.out");

    int n;
    fin >> n;
    int psum[n+1][3];

    psum[0][0] = 0;
    psum[0][1] = 0;
    psum[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        fin >> c;

        if (c == 'H') psum[i][0] = psum[i-1][0] + 1;
        else psum[i][0] = psum[i-1][0];
        
        if (c == 'P') psum[i][1] = psum[i-1][1] + 1;
        else psum[i][1] = psum[i-1][1];

        if (c == 'S') psum[i][2] = psum[i-1][2] + 1;
        else psum[i][2] = psum[i-1][2];
    }

    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << psum[i][j] << " ";
        }
        cout << endl;
    }*/

    int max_score = 0;

    for (int i = 0; i < n+1; i++) {
        int max_l = max(psum[i][0], max(psum[i][1], psum[i][2]));
        int max_r = max(psum[n][0] - psum[i][0], max(psum[n][1] - psum[i][1], psum[n][2] - psum[i][2]));
        max_score = max(max_score, max_l + max_r);
    }

    fout << max_score;
    fin.close();
    fout.close();
    return 0;
}