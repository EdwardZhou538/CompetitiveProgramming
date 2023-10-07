#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("subsegment.in", "r", stdin);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        bool occurred = false;
        for (int i = 0 ; i < n; i++) {
            int a; cin >> a;
            if (a == k && !occurred) {
                occurred = true;
                cout << "YES" << endl;
            }
        }
        if (!occurred) cout << "NO" << endl;
    }
}