#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjacent_same;
vector<vector<int>> adjacent_diff;
vector<int> visited;

vector<int>group;


bool dfs(int node, int type) {
    bool is_possible = true;
    visited[node] = true;
    group[node] = type;

    for (auto neighbor: adjacent_same[node]) {
        if (!is_possible) break;
        if (visited[neighbor]) {
            if (type == 1 && group[neighbor] == 2) {
                cout << "urmom" << endl;
                is_possible = false;
            }
            if (type == 2 && group[neighbor] == 1) {
                cout << "urdad" << endl;
                is_possible = false;
            }
        }
        else {
            is_possible = dfs(neighbor, type);
        }
    }

    for (auto neighbor: adjacent_diff[node]) {
        if (!is_possible) break;
        if (visited[neighbor]) {
            if (type == 1 && group[neighbor] == 1) {
                cout << "gay" << endl;
                is_possible = false;
            }
            if (type == 2 && group[neighbor] == 2) {
                cout << "straight" << endl;
                is_possible = false;
            }
        }
        else {
            is_possible = dfs(neighbor, type % 2 + 1);
        }
    }
    return is_possible;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("revegetate.in");
    fout.open("revegetate.out");
    int n, m;
    fin >> n >> m;
    bool is_possible = true;

    for (int i = 0; i < n; i++) {
        visited.push_back(false);
        adjacent_same.push_back({});
        adjacent_diff.push_back({});
        group.push_back(0);
    }

    for (int i = 0; i < m; i++) {
        char pref;
        int v1, v2;

        fin >> pref >> v1 >> v2;

        v1--;
        v2--;
        if (pref == 'S') {
            for (auto neighbor: adjacent_diff[v1]) {
                if (neighbor == v2) is_possible = false;
            }
            adjacent_same[v1].push_back(v2);
            adjacent_same[v2].push_back(v1);
        }
        else {
            for (auto neighbor: adjacent_same[v1]) {
                if (neighbor == v2) is_possible = false;
            }
            adjacent_diff[v1].push_back(v2);
            adjacent_diff[v2].push_back(v1);
        }
    }
    int num_cc = 0;

    for (int i = 0; i < n; i++) {
        if (!is_possible) break;
        if (!visited[i]) {
            is_possible = dfs(i, 1);
            num_cc++;
        }
    }

    if (!is_possible) fout << 0;
    else {
        fout << 1;
        for (int i = 0; i < num_cc; i++) fout << 0;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}