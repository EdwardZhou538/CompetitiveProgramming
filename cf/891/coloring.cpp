#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 2) cout << "NO" << endl;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        total += val;
    }
    if (total % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //freopen("coloring.in", "r", stdin);
    int t; 
    cin >> t;

    for (int i = 0; i < t; i++) solve();
}