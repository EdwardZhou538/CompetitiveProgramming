#include <bits/stdc++.h>

using namespace std;

int last_true(int l, int r, function<bool(int)> f) {
    
    while (l < r) {
        int m = l + (r-l)/2;
        if (f(m)) {
            r = m;
        }
        else {
            l = m+1;
        }
    }
    return l;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("convention.in");
    fout.open("convention.out");

    int n, m, c;
    fin >> n >> m >> c;

    int cows[n];
    for (int i = 0; i < n; i++) fin >> cows[i];

    sort(cows, cows + n);
    fout << last_true(0, cows[n-1]-cows[0], [&](int x) {
        int idx = 0;
        for (int i = 0; i < m; i++) {
            int cow_1 = idx;
            while (idx - cow_1 < c && cows[idx] - cows[cow_1] <= x) {
                idx++;
                if (idx == n) return true;
            }
        }
        return false;
    });
    fin.close();
    fout.close();
    return 0;
}