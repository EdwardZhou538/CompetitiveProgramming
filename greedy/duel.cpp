#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("duel.in", "r", stdin);
    int n, m; cin >> n >> m;

    pair<int, int> re[n];
    int act[m];
    int num_def = n;
    for (int i = 0; i < n; i++) {
        string action;
        cin >> action;
        re[i].second = (action == "ATK") ? 1 : 0;
        cin >> re[i].first;
        num_def -= re[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> act[i];
    }

    int skip_score = 0;
    int no_skip = 0;
    int l_act = 0, r_act = m-1;
    int l_re = 0;

    sort(re, re+n);
    sort(act, act+m);

    for (int i = 0; i < n; i++) cout << re[i].first << "/" << re[i].second << " ";
    cout << endl;
    for (int i = 0; i < m; i++) cout << act[i] << " ";
    cout << endl;

    while (r_act >= 0 && l_re < n) {
        if (re[l_re].second == 0) {
            l_re++;
            continue;
        }
        else if (re[l_re].first >= act[r_act]) break;
        else {
            skip_score += act[r_act] - re[l_re].first;
            r_act--;
            l_re++;
        }
    }

    int def[num_def];
    int def_idx = 0;
    

    l_re = 0;

    for (int i = 0; i < num_def; i++) {
        while(re[l_re].second != 0) l_re++;
        while (l_act < m && re[l_re].first >= act[l_act]) l_act++;
        def[i] = l_act;
    }

    l_re = 0;
    l_act = 0;
    while (l_re < n) {
        while (l_act < m && re[l_re].first > act[l_act]) {
            no_skip += act[l_act];
            l_act++;
        }
        if (l_act >= m) break;
        else if (re[l_re].second == 0) {
            while (l_act < m && re[l_re].first == act[l_act]) {
                no_skip += act[l_act];
                l_act++;
            }
            l_act++;
            l_re++;
        }
        else {
            no_skip += act[l_act] - re[l_re].first;
            l_act++;
            l_re++;
        }
    }
    if (l_re < n) no_skip = 0;
    else {
        while (l_act < m) {
            no_skip += act[l_act];
            l_act++;
        }
    }
    int max_dmg = max(skip_score, no_skip);
    cout << max_dmg;
    return 0;

}