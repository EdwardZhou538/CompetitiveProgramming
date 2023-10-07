#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;

int dfs(int node) {
    int num_visited = 1;
    visited[node] = true;
    for (auto neighbor: nodes[node]) {
        if (!visited[neighbor]) {
            num_visited += dfs(neighbor);
        }
    }

    return num_visited;
}

int main() {
    //freopen("routes.in", "r", stdin);

    int n, m; cin >> n >> m;


    for (int i = 0; i < n; i++) {
        nodes.push_back({});
        visited.push_back(false);
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        nodes[--a].push_back(--b);
    }

    bool fcg = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[j] = false;
        }
        if (dfs(i) != n) {
            fcg = false;
            cout << "NO" << endl;
            cout << i+1 << " ";
            for (int j = 0; j < n; j++) {
                if (!visited[j]) {
                    cout << j + 1 << endl;
                    break;
                }
            }
        }
    }
    if (fcg) cout << "YES";
}