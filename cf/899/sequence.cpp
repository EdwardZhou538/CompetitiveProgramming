#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int b = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (++b == a) b++;
    }
    cout << b << endl;
}

int main() {
    //freopen("sequence.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}