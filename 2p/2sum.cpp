#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("2sum.in", "r", stdin);
    int n, x;
    cin >> n >> x;

    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr, arr+n);
    int l = 0, r = 1;
    while (arr[l].first + arr[r].first < x) {
        if (r >= n-1) {
            l++;
        }
        else r++;
        if (arr[l].first + arr[r].first > x) {
            l++;
            r--;
        }
        while (l < r && arr[l].first + arr[r].first > x) {
            r--;
        }
        if (l >= r) break;
    }

    if (l < r && arr[l].first + arr[r].first == x) cout << arr[l].second << " " << arr[r].second;
    else cout << "IMPOSSIBLE";
    return 0;
}