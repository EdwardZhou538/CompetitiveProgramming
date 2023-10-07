#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("factory.in");
    fout.open("factory.out");

    int n;
    fin >> n;
    
    vector<int> stations[n];

    for (int i = 0; i < n-1; i++) {
        int s1, s2;
        fin >> s1 >> s2;

        stations[s2-1].push_back(s1-1);
    }

    bool station_exists = false;
    for (int i = 0; i < n; i++) {
        bool visited[n];
        int num_visited = 1;
        for (int j = 0; j < n; j++) {
            visited[j] = false;
        }
        visited[i] = true;

        stack<int> stack;
        for (int j = 0; j < stations[i].size(); j++) {
            stack.push(stations[i][j]);
        }
        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();
            visited[current] = true;
            num_visited++;
            for (int j = 0; j < stations[current].size(); j++) {
                if (!visited[stations[current][j]]) {
                    stack.push(stations[current][j]);
                }
            }
        }
        if (num_visited == n) {
            station_exists = true;
            fout << i + 1;
            break;
        }
    }

    if (!station_exists) fout << -1;
    fin.close();
    fout.close();
    return 0;
}