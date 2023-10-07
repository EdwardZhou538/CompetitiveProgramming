#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("bipartite.in", "r", stdin);

    long long n;
    cin >> n;

    vector<int> adjacent[n];
    for (int i = 0; i < n-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        adjacent[--v1].push_back(--v2);
        adjacent[v2].push_back(v1);
    }
    bool visited[n];
    int group[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        group[i] = 0;
    }

    int start_node = 0;
    visited[start_node] = true;
    group[start_node] = 1;
    queue<int> q;
    long long num_1 = 1;
    q.push(start_node);
    while(!q.empty()) {
        int curr_node = q.front();
        q.pop();
        for (auto neighbor: adjacent[curr_node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                group[neighbor] = group[curr_node] % 2 + 1;
                if (group[neighbor] == 1) num_1++;
            }
        }
    }

    cout << num_1 * (n - num_1) - n + 1;

    return 0;
}