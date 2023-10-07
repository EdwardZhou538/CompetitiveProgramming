#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int fruits[n];
    int height[n];
    int max_len = 0;
    for (int i = 0 ; i < n; i++) {
        cin >> fruits[i];
        if (fruits[i] <= k) {
            max_len = 1;
        }
    }
    for (int i = 0; i < n; i++) cin >> height[i];

    int idx= 0;

    while (idx < n-1) {
        if (height[idx] % height[idx+1] == 0 && fruits[idx] <= k) {
            //cout << idx << endl;
            int l = idx;
            int r = idx+1;
            int val = fruits[l];
            while (r < n && height[r-1] % height[r] == 0) {
                //cout << height[r] << endl;
                val += fruits[r];
                while (val > k) {
                    val -= fruits[l];
                    l++;
                }
                //cout << val << " " << r << endl;
                max_len = max(max_len, r-l+1);
                r++;
            }
            idx = r;
        }
        else idx++;
    }
    cout << max_len << endl;
}

int main() {
    //freopen("money.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}