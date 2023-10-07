#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    if (n == 0) {
        cout << 0;
        return;
    }
    int num_coins = 0;
    int num_a = 0;
    int l = 0, r = 0;
    if (s.at(l) == 'A') num_a++;
    while (r < n-1) {
        r++;
        if (s.at(r) == 'A') num_a++;
        if (s.at(r) == 'B' && s.at(r-1) == 'B') {
            num_coins += num_a;
            num_a = 0;
            while (r < n && s.at(r) == 'B') r++;
            r--;
            l = r;
        }
    }
    if (l != 0) num_coins += num_a;
    else {
        if (s.at(l) == 'B' || s.at(r) == 'B') num_coins = num_a;
        else if (num_a == n) num_coins = 0;
        else {
            int l_a = 0;
            int r_a = 0;
            while (s.at(l) == 'A') {
                l_a++;
                l++;
            }
            while (s.at(r) == 'A') {
                r_a++;
                r--;
            }
            num_coins = num_a - min(r_a, l_a);
        }
    }
    cout << num_coins << endl;
}

int main() {
    //freopen("abbc.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}