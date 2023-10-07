#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.at(0) == 'a' || s.at(1) == 'b' || s.at(2) == 'c') cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    //freopen("shortsort.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}