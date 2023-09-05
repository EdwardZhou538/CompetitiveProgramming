#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("cbarn.in");
    int n;
    fin >> n;
    int dest[n];
    for (int i = 0; i < n; i++) {
        fin >> dest[i];
    }
    int min_dist = 0;

    for (int i = 0; i < n; i++) {
        int dist = 0;
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                dist += (j - i) * dest[j];
            }
            else {
                dist += (n - i + j) * dest[j];
            }
        }
        if (i == 0) min_dist = dist;
        else min_dist = min(min_dist, dist);
    }
    fout.open("cbarn.out");
    fout << min_dist;
    fin.close();
    fout.close();
    
}