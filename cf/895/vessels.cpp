#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << 0 << endl;
        return;
    }

    cout << (abs(a - b) - 1) / (2*c) + 1 << endl;
}

int main() {
    //freopen("vessels.in", "r", stdin);

    int t;

    cin >> t;
    for (int i = 0; i < t; i++) solve();
}