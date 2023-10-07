#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;

    bool solved = false;

    for (int i = l; i <= r; i++) {
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                solved = true;
                cout << j << " " << i - j << endl;
                break;
            }
        }
        if (solved) break;
    }
    if(!solved) cout << -1 << endl;
}

int main() {
    //freopen("split.in", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}