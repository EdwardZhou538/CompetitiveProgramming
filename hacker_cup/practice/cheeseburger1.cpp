#include <bits/stdc++.h>
using namespace std;

void solve(int i) {
    int s, d, k;
    cin >> s >> d >> k;
    if (s + 2*d >= k && 2*s + 2*d >= k+1) {
        printf("Case #%d: YES\n", i);
    }
    else printf("Case #%d: NO\n", i);
}

int main() {
    freopen("cheeseburger1.in", "r", stdin);
    freopen("cheeseburger1.txt", "w", stdout);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}