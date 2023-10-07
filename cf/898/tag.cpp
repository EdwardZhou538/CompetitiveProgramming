#include <bits/stdc++.h>
using namespace std;



void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> adjacent[n];
    bool visited[n];
    int distance[n];
    int parent[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        int v1, v2;
        cin >> v1 >> v2;
        adjacent[--v1].push_back(--v2);
        adjacent[v2].push_back(v1);
    }
    distance[--b] = 0;
    queue<int> q;
    visited[b] = true;
    q.push(b);
    int closest_cycle = -1;
    int min_dist = INT_MAX;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto neighbor: adjacent[curr]) {
            if (visited[neighbor]) {
                if (parent[curr] != neighbor) {
                    if (distance[neighbor] < min_dist) {
                        min_dist = distance[neighbor];
                        closest_cycle = neighbor;
                    }
                }
                continue;
            }
            parent[neighbor] = curr;
            distance[neighbor] = distance[curr] + 1;
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
    if (closest_cycle == -1) cout << "NO" << endl;
    else if (--a == closest_cycle) cout << "NO" << endl;
    else {
        for (int i = 0; i < n; i++) {
            if (i == a) {
                distance[i] = 0;
            }
            else {
                visited[i] = false;
                
            }
        }
        q.push(a);
        bool break_loop = false;
        while (!q.empty()) {
            if (break_loop) break;
            int curr = q.front();
            q.pop();
            for (auto neighbor: adjacent[curr]) {
                if (visited[neighbor]) continue;
                if (neighbor == closest_cycle) {
                    if (distance[curr] + 1 > min_dist) cout << "NO" << endl;
                    else cout << "YES" << endl;
                    break_loop = true;
                    break;
                }
                distance[neighbor] = distance[curr] + 1;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }


}

int main() {
    freopen("tag.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}