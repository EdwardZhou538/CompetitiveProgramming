#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int min_diff = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        min_diff = min(min_diff, arr[i+1] - arr[i]);
    }
    if (min_diff < 0) cout << 0 << endl;
    else cout << min_diff/2 + 1 << endl;
}

int main() {
    //freopen("desorting.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}