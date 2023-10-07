#include <bits/stdc++.h>

using namespace std;

int backtrack(vector<vector<int>>& zero, vector<vector<int>>& high, int val1, int val2) {
    
    if (val1 >= zero.size() || val2 >= high.size()) {
        for (int i = 0; i < high.size(); i++) {
            if (high[i][2] > 1) return 100;
        }
        return 0;
    }
    cout << val1 << " " << val2 << endl;
    
    if (high[val2][2] > 1 && zero[val1][2] == 0) {
        high[val2][2]--;
        zero[val1][2]++;
        int include_dist = backtrack(zero, high, val1, val2) + abs(high[val2][0] - zero[val1][0]) + abs(high[val2][1] - zero[val1][1]);
        high[val2][2]++;
        zero[val1][2]--;
        int uninclude_dist = backtrack(zero, high, val1+1, val2);
        return min(include_dist, uninclude_dist);
    }
    else if (high[val2][2] == 1) return backtrack(zero, high, val1, val2+1);
    else return backtrack(zero, high, val1+1, val2);
}

int minimumMoves(vector<vector<int>>& grid) {
    vector<vector<int>> zero_vals;
    vector<vector<int>> high_vals;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == 0) zero_vals.push_back({i, j, 0});
            if (grid[i][j] > 1) high_vals.push_back({i, j, grid[i][j]});
        }
    }
    cout << zero_vals.size();
    cout << high_vals.size();
    
    return backtrack(zero_vals, high_vals, 0, 0);
}

int main() {
    freopen("stones.in", "r" , stdin);
    vector<vector<int>> grid;

    for (int i = 0; i < 3; i++) {
        vector<int> something;
        for (int j = 0; j < 3;j ++) {
            int n;
            cin >> n;
            something.push_back(n);
        }
        grid.push_back(something);
    }
    cout << minimumMoves(grid);
    return 0;
}



