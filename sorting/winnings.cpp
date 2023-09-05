#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;

    cin >> n >> m;

    long long cards[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cards[j][i];
        }
    }

    long long total = 0;

    for (int i = 0; i < m; i++ ){
        sort(cards[i], cards[i]+n);

        for (int j = 0; j < n; j++) {
            total += cards[i][j] * (2*j - n+1);
        }
        //cout << endl;
    }

    cout << total << endl;
}

int main() {
    //freopen("winnings.in", "r", stdin);
    
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) solve();
}