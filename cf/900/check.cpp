#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k, x; cin >> n >> k >> x;

    if (x >= k*(k+1)/2 && x <= n*(n+1)/2-(n-k)*(n-k+1)/2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //freopen("check.in", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
}