#include <bits/stdc++.h>
using namespace std;

void solve(int i) {
    long long a, b, c; cin >> a >> b >> c;
    long long max_k = 0;
    if (b >= a*2) {
        max_k = c/a;
    }
    else if (a >= b) {
        max_k = 2*(c/b) - 1;
    }
    else if (c/b == 1) {
        if (b + a <= c) max_k = 3;
        else if (2 * a <= c) max_k = 2;
        else max_k = 1;
    }
    else {
        max_k = 2*(c/b) - 1;
        if (c - b*(c/b) >= a) max_k += 2;
    }
    max_k = max(max_k, (long long)0);
    cout << "Case #" << i << ": " << max_k << endl;
}

int main() {
    freopen("cheeseburger2.in", "r", stdin);
    freopen("cheeseburger2.txt", "w", stdout);

    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}