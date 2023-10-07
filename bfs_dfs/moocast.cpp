#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;

int dfs(int n) {
    int num_visited = 1;
    visited[n] = true;
    for (auto neighbor: nodes[n]) {
        if (!visited[neighbor]) num_visited += dfs(neighbor);
    }
    return num_visited;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("moocast.in");
    fout.open("moocast.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        nodes.push_back({});
        visited.push_back(false);
    }

    int cows[n][3];

    for (int i = 0; i < n; i++) {
        fin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (int(pow(cows[j][0] - cows[i][0], 2) + pow(cows[j][1] - cows[i][1], 2)) <= int(pow(cows[i][2], 2))) nodes[i].push_back(j);
        }
    }
    int max_cows = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) visited[j] = false;
        max_cows = max(max_cows, dfs(i));
    }
    fout << max_cows;
    fin.close();
    fout.close();
    return 0;
}