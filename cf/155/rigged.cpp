#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    pair<int, int> monocarp;
    cin >> monocarp.first >> monocarp.second;
    bool impossible = false;
    for (int i = 0; i < n-1; i++) {
        pair<int, int> other_athlete;
        cin >> other_athlete.first >> other_athlete.second;
        if (other_athlete.first >= monocarp.first && other_athlete.second >= monocarp.second) impossible = true;
    }

    if(impossible) cout << -1 << endl;
    else cout << monocarp.first << endl;
}

int main() {
    //freopen("rigged.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}