#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("highcard.in");
    fout.open("highcard.out");
    int n; fin >> n;
    int elsie[n];
    for (int i = 0; i < n; i++) fin >> elsie[i];
    sort(elsie, elsie+n);
    int elsie_idx = 0;
    int bessie_idx = 0;
    int bessie[n];
    for (int i = 1; i <= 2*n; i++) {
        if (elsie[elsie_idx] == i) elsie_idx++;
        else {
            bessie[bessie_idx] = i;
            bessie_idx++;
        }
    }
    bessie_idx = 0;
    elsie_idx = 0;
    int num_points = 0;
    while (elsie_idx < n) {
        while (bessie_idx < n && bessie[bessie_idx] < elsie[elsie_idx]) {
            bessie_idx++;
        }
        if (bessie_idx == n) break;
        num_points++;
        bessie_idx++;
        elsie_idx++;
    }
    fout << num_points;
    fin.close();
    fout.close();
    return 0;
}