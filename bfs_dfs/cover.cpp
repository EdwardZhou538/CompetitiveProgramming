#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;

    cin >> n >> m;
    vector<int> adjacent[n];
    bool visited[n];
    int group[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        group[i] = 0;
    }


    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adjacent[--v1].push_back(--v2);
        adjacent[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        group[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int current_node = q.front();
            q.pop();
            //cout << current_node << endl;
            for (auto neighbor: adjacent[current_node]) {
                if (visited[neighbor]) continue;
                group[neighbor] = group[current_node] % 2 + 1;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    int num_1 = 0, num_2 = 0;

    for (int i = 0; i < n; i++) {
        if (group[i] == 1) num_1++;
        else num_2++;
    }
    if (num_1 > num_2) {
        cout << num_2 << endl;
        for (int i = 0; i < n; i++) {
            if (group[i] == 2) cout << i+1 << " ";
        }
    }
    else {
        cout << num_1 << endl;
        for (int i = 0; i < n; i++) {
            if (group[i] == 1) cout << i+1 << " ";
        }
    }
    cout << endl;
}

int main() {
    //freopen("cover.in", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) solve();

}