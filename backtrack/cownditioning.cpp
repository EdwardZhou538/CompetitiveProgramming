#include <bits/stdc++.h>

using namespace std;

int min_cost(int cooling[], vector<vector<int>>& ac, int idx) {
    if (idx >= ac.size()) {
        for (int i = 0; i < 101; i++) {
            if (cooling[i]!= 0) {
                return 10e6;
            }
        }
        return 0;
    }
    //cout << "Index: " << idx << endl;
    
    int sub[ac[idx][1] - ac[idx][0] + 1];
    for (int i = ac[idx][0]; i <= ac[idx][1]; i++) {
        sub[i - ac[idx][0]] = min(ac[idx][2], cooling[i]);
        cooling[i] -= min(ac[idx][2], cooling[i]);
    }
    int use_price = ac[idx][3] + min_cost(cooling, ac, idx + 1);

    for (int i = ac[idx][0]; i <= ac[idx][1]; i++) {
        cooling[i] += sub[i - ac[idx][0]];
    }
    int unuse_price = min_cost(cooling, ac, idx + 1);
    return min(use_price, unuse_price);

}
int main() {
    //freopen("cownditioning.in", "r", stdin);

    int n, m;
    cin >> n >> m;

    int cooling[101];
    for (int i = 0; i < 101; i++) cooling[i] = 0;

    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        for (int j = l; j <= r; j++) cooling[j] = c;
    }

    vector<vector<int>> ac;

    for (int i = 0; i < m; i++) {
        vector<int> something;
        for (int j = 0; j < 4; j++) {
            int val;
            cin >> val;
            something.push_back(val);
        }
        ac.push_back(something);
    }
    //cout << "do we get here" << endl;
    cout << min_cost(cooling, ac, 0);

    return 0;
}