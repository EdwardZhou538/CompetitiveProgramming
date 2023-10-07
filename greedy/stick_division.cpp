#include <bits/stdc++.h>

using namespace std;
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    //freopen("stick_division.in", "r", stdin);
    int x, n; cin >> x >> n;
    long long lengths[n];
    for (int i = 0; i < n; i++) cin >> lengths[i];
    sort(lengths, lengths+n, cmp);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += (i+1) * lengths[i];
    }
    total -= lengths[n-1];
    cout << total;
    return 0;
}