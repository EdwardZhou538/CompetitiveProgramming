#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int last_valid(long long l, long long r, function<bool(long long)> f) {
    while (l < r) {
        long long m = l+(r-l+1) / 2;
        if (f(m)) l = m;
        else r = m-1;
    }
    return l;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("socdist.in");
    fout.open("socdist.out");
    int n, m;
    fin >> n >> m;
    pair<int, int> farm[m];
    for (int i = 0; i < m; i++) fin >> farm[i].f >> farm[i].s;
    sort(farm, farm+m);

    fout << last_valid(1, farm[m-1].s - farm[0].f, [&](long long x) {
        long long current_cow = farm[0].f;
        int current_range = 0;
        for (int i = 1; i < n; i++) {
            if (current_cow + x > farm[m-1].s) return false;
            while (current_cow + x > farm[current_range].s) {
                current_range++;
            }
            current_cow = max(current_cow + x, farm[current_range].f);
        }
        return true;
    });
    fin.close();
    fout.close();
    return 0;
}