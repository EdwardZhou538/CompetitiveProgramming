#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
vector<bool> closed;

vector<vector<int>> cc;

int dfs(int node) {
    int visited_nodes = 1;
    visited[node] = true;
    for (auto neighbor: nodes[node]) {
        if (!visited[neighbor]) visited_nodes += dfs(neighbor);
    }
    return visited_nodes;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("closing.in");
    fout.open("closing.out");

    int n, m; fin >> n >> m;

    for (int i = 0; i < n; i++) {
        nodes.push_back({});
        visited.push_back(false);
        closed.push_back(false);
    }

    for (int i = 0; i < m; i++) {
        int b1, b2; fin >> b1 >> b2;
        nodes[--b1].push_back(--b2);
        nodes[b2].push_back(b1);
    }

    if (dfs(0) < n) fout << "NO" << endl;
    else fout << "YES" << endl;

    for (int i = 0; i < n-2; i++) {
        int closing;
        fin >> closing;

        closed[--closing] = true;
        for (int j = 0; j < n; j++) visited[j] = closed[j];
        int start = 0;
        while(visited[start]) start++;
        if (dfs(start) < n-i-1) fout << "NO" << endl;
        else fout << "YES" << endl;
    }

    fout << "YES" << endl;
    fin.close();
    fout.close();
    return 0;

}
