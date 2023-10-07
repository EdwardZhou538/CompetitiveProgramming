#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    pair<int, int> a[n];
    pair<int, int> b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> b[i].first;
        a[i].second = i;
        b[i].second = i;
    }
    sort(a, a+n);
    sort(b, b+n);

    int ai = 0, bi = 0;
    int min_diff = INT_MAX;
    while (ai < n && bi < n) {
        if (a[ai].first == b[bi].first) {
            if (a[ai].second != b[bi].second) {
                cout << 0 << endl;
                return;
            }
            else {
                ai++;
            }
        }
        while (ai < n && a[ai].first < b[bi].first) {
            if (a[ai].second != b[bi].second) min_diff = min(min_diff, b[bi].first - a[ai].first);
            ai++;
        }
        if (ai == n) break;

        if (b[bi].second != a[ai].second) min_diff = min(min_diff, a[ai].first - b[bi].first);
        while (bi < n && b[bi].first < a[ai].first) {
            if (a[ai].second != b[bi].second) min_diff= min(min_diff, a[ai].first - b[bi].first);
            bi++;
        }
        if (bi == n) break;
        if (b[bi].second != a[ai].second) min_diff = min(min_diff, b[bi].first - a[ai].first);
    }

    if (ai == n && bi < n-1 && a[ai-1].second == b[bi].second) {
        min_diff = min(min_diff, b[bi+1].first - a[ai-1].first);
    }

    if (bi == n && ai < n-1 && a[ai].second == b[bi-1].second) {
        min_diff = min(min_diff, a[ai+1].first - b[bi-1].first);
    }

    cout << min_diff << endl;
}

int main() {
    //freopen("gifts.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}