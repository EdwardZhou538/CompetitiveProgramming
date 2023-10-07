#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        int l, k; cin >> l >> k;
        l--;
        int r = l;
        int val = arr[l];
        if (val < k) {
            cout << -1 << " ";
            continue;
        }
        while (r < n) {
            val = val & arr[r];
            if (val < k) {
                cout << r << " ";
                break;
            }
            r++;
        }
        if (r == n) cout << r << " ";
    }
    cout << endl;
}

int main() {
    //freopen("pav.in", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
}