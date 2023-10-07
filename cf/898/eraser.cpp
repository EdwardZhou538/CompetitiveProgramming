#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int i = 0;
    int num_operations = 0;
    while (i < n) {
        if (s.at(i) == 'B') {
            num_operations++;
            i += k;
        }
        else i++;
    }
    cout << num_operations << endl;
}

int main() {
    //freopen("eraser.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}