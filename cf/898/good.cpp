#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n];
    int min_val = INT_MAX;
    bool added = false;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        min_val = min(arr[i], min_val);
    }
    int prod = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == min_val && !added) {
            prod *= arr[i] + 1;
            added = true;
        }
        else prod *= arr[i];
    }
    cout << prod << endl;
}

int main() {
    //freopen("good.in", "r", stdin);

    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}