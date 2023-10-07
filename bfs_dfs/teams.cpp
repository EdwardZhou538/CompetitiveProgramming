#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> nodes;

int main() {
    //freopen("teams.in", "r", stdin);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        visited.push_back(false);
        nodes.push_back({});
    }

    for (int i = 0; i < m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        nodes[--p1].push_back(--p2);
        nodes[p2].push_back(p1);
    }

    int team[n];
    for (int i = 0; i < n; i++) team[i] = true;
    bool impossible = false;

    for (int i = 0; i < n; i++) {
        if (impossible) break;
        if (visited[i]) continue;

        queue<pair<int, int>> distance;
        visited[i] = true;
        distance.push({i, 0});
        while (!distance.empty()) {
            if (impossible) break;

            int current_node = distance.front().first;
            int current_dist = distance.front().second;
            //cout << current_node << " " << current_dist << endl;
            team[current_node] = current_dist % 2 + 1;
            visited[current_node] = true;
            distance.pop();
            for (auto neighbor: nodes[current_node]) {
                if (visited[neighbor]) {
                    if (current_dist % 2 == 0 && team[neighbor] == 1) {
                        cout << "IMPOSSIBLE";
                        impossible = true;
                        break;
                    }
                    if (current_dist % 2 == 1 && team[neighbor] == 2) {
                        cout << "IMPOSSIBLE";
                        impossible = true;
                        break;
                    }
                    continue;
                }
                distance.push({neighbor, current_dist + 1});

            }


        }
        
    }

    if (!impossible) {
        for (int i = 0; i < n; i++) {
            cout << team[i] << " ";
        }
    }
    return 0;
}