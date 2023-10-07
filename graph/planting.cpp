#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("planting.in");
    fout.open("planting.out");

    int n;
    fin >> n;
    vector<int> graph[n+1];

    for (int i = 0; i < n-1; i++) {
        int v1, v2;
        fin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

        
    }
}