#include <bits/stdc++.h>

using namespace std;

bool check_valid(multiset<int> ms, int max_val, int rm_val) {
    ms.erase(ms.find(rm_val));
    auto pt = ms.end();
    int current_greatest = *(--pt);
    vector<pair<int, int>> operations;
    if (max_val == current_greatest * 2) {
        if (ms.count(current_greatest) < 2) return false;
        else {
            ms.erase(ms.find(current_greatest));
            ms.erase(ms.find(current_greatest));
            operations.push_back({current_greatest, current_greatest});
        }
    }
    else {
        if (ms.find(max_val - current_greatest) == ms.end()) return false;
        else {
            operations.push_back({max_val - current_greatest, current_greatest});
            ms.erase(ms.find(current_greatest));
            ms.erase(ms.find(max_val - current_greatest));
        }
    }
    while (!ms.empty()) {
        pt = ms.end();
        int next_greatest = *(--pt);
        if (current_greatest == next_greatest * 2) {
            if (ms.count(next_greatest) < 2) return false;
            else {
                operations.push_back({next_greatest, next_greatest});
                ms.erase(ms.find(next_greatest));
                ms.erase(ms.find(next_greatest));
                current_greatest = next_greatest;
            }
        }
        else {
            if (ms.find(current_greatest - next_greatest) == ms.end()) return false;
            else {
                operations.push_back({current_greatest - next_greatest, next_greatest});
                ms.erase(ms.find(next_greatest));
                ms.erase(ms.find(current_greatest - next_greatest));
                current_greatest = next_greatest;
            }
        }
    }
    cout << "YES" << endl;
    cout << max_val + rm_val << endl;
    cout << rm_val << " " << max_val << endl;
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i].first << " " << operations[i].second << endl;
    }
    return true;
}

void solve() {
    int n; cin >> n;

    multiset<int> ms;
    for (int i = 0; i < n*2; i++) {
        int k; cin >> k;
        ms.insert(k);
    }

    auto pt = ms.end();
    int max_val = *(--pt);
    ms.erase(ms.find(max_val));
    auto it = ms.begin();
    while (it != ms.end()) {
        if(check_valid(ms, max_val, *it)) break;
        it++;
    }

    if (it == ms.end()) cout << "NO" << endl;
}

int main() {
    //freopen("destruction.in", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}