#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
int main() {

    ifstream fin;
    ofstream fout;

    fin.open("lifeguards.in");
    fout.open("lifeguards.out");

    int n; fin >> n;
    vector<vector<int>> shifts;
    for(int i = 0; i < n; i++) {
        int s, e;
        fin >> s >> e;
        shifts.push_back({s,e});
    }
    sort(shifts.begin(), shifts.end(), cmp);

    int total_time = 0;
    bool contains_shift = false;
    int idx = 0;
    while (idx < n-1) {
        int idx2 = idx+1;
        while(shifts[idx2][1] < shifts[idx][1]) {
            contains_shift = true;
            idx2++;
        }
        total_time += min(shifts[idx][1], shifts[idx2][0]) - shifts[idx][0];
        idx = idx2;
    }
    if (idx == n)
    total_time += shifts[n-1][1] - shifts[n-1][0];
    if (contains_shift) fout << total_time;
    else {
        int start_shift = min(shifts[0][1], shifts[1][0]) - shifts[0][0];
        int end_shift = shifts[n-1][1] - max(shifts[n-1][0], shifts[n-2][1]);
        int min_time = min(start_shift, end_shift);

        for (int i = 1; i < n-1; i++) {
            int block_len = shifts[i][1] - shifts[i][0];
            int l_overlap = max(shifts[i-1][1], shifts[i][0]) - shifts[i][0];
            int r_overlap = shifts[i][1] - min(shifts[i+1][0], shifts[i][1]);
            min_time = min(min_time, max(0, block_len - l_overlap - r_overlap));
        }
        fout << total_time - min_time;
    }
    fin.close();
    fout.close();
    return 0;
}