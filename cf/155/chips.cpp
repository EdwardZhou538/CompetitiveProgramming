#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    long long min_a = LLONG_MAX;
    long long sum_a = 0;
    long long min_b = LLONG_MAX;
    long long sum_b = 0;
    for (int i = 0; i < n; i++) {
        long long val; cin >> val;
        min_a = min(min_a, val);
        sum_a += val;
    }
    for (int i = 0; i < n; i++) {
        long long val; cin >> val;
        min_b = min(min_b, val);
        sum_b += val;
    }

    cout << min(min_a*n + sum_b, min_b*n + sum_a) << endl;
}

int main() {
    //freopen("chips.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++)solve();
}