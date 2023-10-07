#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    int l = (n-1) / 2;
    int r = l + 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << arr[l] << " ";
            l--;
        }
        else {
            cout << arr[r] << " ";
            r++;
        }
    }
    cout << endl;
}

int main() {
    //freopen("adjdiff.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}