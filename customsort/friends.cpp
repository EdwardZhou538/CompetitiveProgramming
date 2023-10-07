#include <bits/stdc++.h>

using namespace std;

struct triplet {
    int f;
    int s;
    int t;
};

bool cmp(triplet a, triplet b) {
    return a.f < b.f || (a.f == b.f && a.s > b.s);
    
}

void solve() {
    int n;
    cin >> n;
    triplet friends[n];
    for (int i = 0; i < n; i++) {
        cin >> friends[i].f >> friends[i].s;
        if (friends[i].f > friends[i].s) swap(friends[i].f, friends[i].s);
        friends[i].t = i;
    }

    sort (friends, friends + n, cmp);
    int min_height = INT_MAX;
    int idx = -1;

    int alignment[n];

    for (int i = 0; i < n; i++) {
        if (min_height > friends[i].s) {
            min_height = friends[i].s;
            idx = friends[i].t;
            alignment[idx] = -2;
        }
        else {
            alignment[friends[i].t] = idx;
        }
    }

    for (int i = 0; i < n; i++) cout << alignment[i] + 1 << " ";
    cout << endl;
}

int main() {
    freopen("friends.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}