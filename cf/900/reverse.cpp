#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int l[k];
    int r[k];
    for (int i = 0; i < k; i++) {
        cin >> l[i];
        l[i]--;
    }
    for (int i = 0; i < k; i++) {
        cin >> r[i];
        r[i]--;
    }
    int q; cin >> q;
    vector<int> counts[k];
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        x--;

        int l1 = 0, r1 = k;
        int m = (l1+r1)/2;
        while (x < l[m] || x > r[m]) {
            if (x < l[m]) {
                r1 = m;
                m = (l1+r1)/2;
            }
            else {
                l1 = m+1;
                m = (l1+r1)/2;
            }
        }
        int a = min(x, l[m] + r[m]-x);
        counts[m].push_back(a);
        //cout << a << " " << b << endl;
    }
    for (int i = 0; i < k; i++) {
        sort(counts[i].begin(), counts[i].end());
        for (int j = 0; j < counts[i].size(); j++) {
           // cout << counts[i][j] << " ";
            if (j % 2 == 0) {
                if (j == counts[i].size() - 1) {
                    for (int p = counts[i][j]; p <= (l[i] + r[i])/2; p++) {
                        swap(s[p], s[l[i] + r[i] - p]);
                    }
                }
                else {
                    for (int p = counts[i][j]; p < counts[i][j+1]; p++) {
                        swap(s[p], s[l[i] + r[i] - p]);
                    }
                }
            }
        }
        //cout << endl;
    }
    cout << s << endl;

}

int main() {
    //freopen("reverse.in", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
}