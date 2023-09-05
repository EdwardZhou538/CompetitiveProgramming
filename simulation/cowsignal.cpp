#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("cowsignal.in");
    int m;
    int n;
    int k;
    fin >> m >> n >> k;

    char pic[m][n];
    for (int i = 0; i < m; i++) {
        string row;
        fin >> row;
        for (int j = 0; j < n; j++) {
            pic[i][j] = row.at(j);
        }
    }

    char big_pic[k*m][k*n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int o = 0; o < k; o++) {
                for (int p = 0; p < k; p++) {
                    big_pic[k*i+o][k*j+p] = pic[i][j];
                }
            }
        }
    }
    fout.open("cowsignal.out");
    for (int i = 0; i < k*m; i++) {
        for (int j = 0; j < k*n; j++) {
            fout << big_pic[i][j];
        }
        fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}