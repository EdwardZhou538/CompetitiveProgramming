#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
vector<vector<int>> cc;

void dfs(int node, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (auto neighbor: nodes[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, component);
        }
    }
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("fenceplan.in");
    fout.open("fenceplan.out");

    int n, m;
    fin >> n >> m;

    for (int i = 0; i < n; i++) {
        nodes.push_back({});
        visited.push_back(false);
    }

    int coords[n][2];
    for (int i = 0; i < n; i++) fin >> coords[i][0] >> coords[i][1];

    for (int i = 0; i < m; i++) {
        int a, b; fin >> a >> b;

        nodes[--a].push_back(--b);
        nodes[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        vector<int> component;
        dfs(i, component);
        cc.push_back(component);
    }
    int min_perimeter = INT_MAX;

    for (auto component: cc) {
        int min_x = INT_MAX, min_y = INT_MAX;
        int max_x = 0, max_y = 0;

        for (auto node: component) {
            min_x = min(coords[node][0], min_x);
            min_y = min(coords[node][1], min_y);
            max_x = max(coords[node][0], max_x);
            max_y = max(coords[node][1], max_y);
        }
        if (max_x == min_x) min_perimeter = min(min_perimeter, max_y - min_y);
        else if (max_y == min_y) min_perimeter = min(min_perimeter, max_x - min_x);
        else min_perimeter = min(min_perimeter, 2*(max_x + max_y - min_x - min_y));
    }
    fout << min_perimeter;
    fin.close();
    fout.close();
    return 0;
}