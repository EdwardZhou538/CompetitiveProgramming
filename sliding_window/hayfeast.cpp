#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("hayfeast.in");
    fout.open("hayfeast.out");

    int n, m; fin >> n >> m;

    pair<long long, long long> food[n];
    for (int i = 0; i < n; i++) {
        fin >> food[i].first >> food[i].second;
    }

    int l = 0;
    int r = 0;
    long long flavor = 0;
    long long spiciness = 0;
    long long min_spiciness = LLONG_MAX;
    while (l < n) {
        while (r < n && flavor < m) {
            flavor += food[r].first;
            spiciness += food[r].second;
        }
        if (flavor < m) break;
        while (flavor >= m) {
            min_spiciness = min(spiciness, min_spiciness);
            spiciness -= food[l].second;
            flavor -= food[l].first;
            l++;
        }
    }
    fout << min_spiciness;
    return 0;
}