#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> roads;
vector<bool> visited;

void dfs(int node) {
    //cout << node << endl;
    visited[node] = true;
    for (auto adjacent: roads[node]) {
        if (!visited[adjacent]) dfs(adjacent);
    }
}

int main() {
    //freopen("roads.in", "r", stdin);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        roads.push_back({});
        visited.push_back(false);
    }

    for (int i = 0; i < m; i++) {
        int c1, c2; cin >> c1 >> c2;

        roads[--c1].push_back(--c2);
        roads[c2].push_back(c1);
    }

    vector<int> cc;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        cc.push_back(i);
        dfs(i);
    }

    cout << cc.size() - 1 << endl;

    for (int i = 0 ; i < cc.size() - 1; i++) {
        cout << cc[i] + 1 << " " << cc[i+1] + 1 << endl;
    }
    return 0;
}