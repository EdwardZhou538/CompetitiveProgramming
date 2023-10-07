#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int max_dist = INT_MAX;

    for (int i = 0; i < n; i++) {
        int trap, time;
        cin >> trap >> time;
        if (time % 2 == 1) max_dist = min(max_dist, trap + time/2);
        else max_dist = min(max_dist, trap + time/2 - 1);
    }

    cout << max_dist << endl;
}

int main() {
    //freopen("traps.in", "r", stdin);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) solve();
    return 0;
}