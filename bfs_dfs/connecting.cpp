#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> adjacent[n];
    vector<bool> visited[n];
    vector<vector<int>> cc;

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adjacent[--v1].push_back(--v2);
        adjacent[v2].push_back(v1);
    }
}



int main() {
    freopen("connecting.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < n; i++) solve();
}