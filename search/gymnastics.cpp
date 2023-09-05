#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("gymnastics.in");
    int k;
    int n;
    fin >> k >> n;

    int performances[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            fin >> performances[i][j];
        }
    }

    vector<vector<int>> consistent_pairs;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            consistent_pairs.push_back({performances[0][i], performances[0][j]});
        }
    }

    for (int i = 1; i < k; i++) {
        for (int j = consistent_pairs.size() - 1; j >= 0; j--) {
            for (int o = 0; o < n; o++) {
                for (int p = o+1; p < n; p++) {
                    if (consistent_pairs[j][0] == performances[i][p] && consistent_pairs[j][1] == performances[i][o]) {
                        consistent_pairs.erase(consistent_pairs.begin() + j);
                    }
                }
            }
        }
    }

    fout.open("gymnastics.out");
    fout << consistent_pairs.size();
    fin.close();
    fout.close();
    return 0;
}   