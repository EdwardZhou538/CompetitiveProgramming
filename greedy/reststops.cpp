#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("reststops.in");
    fout.open("reststops.out");

    int l, n, rf, rb;
    fin >> l >> n >> rf >> rb;

    pair<long long, long long> stops[n];
    for (int i = 0; i < n; i++) fin >> stops[i].first >> stops[i].second;

    int pos = 0;
    long long grass_eaten = 0;
    sort(stops, stops+n, cmp);
    for (int i = 0; i < n; i++) {
        if (stops[i].first > pos) {
            grass_eaten += (stops[i].first-pos)*(rf-rb)*stops[i].second;
            pos = stops[i].first;
        }
    }
    fout << grass_eaten;
    fin.close();
    fout.close();
    return 0;
}