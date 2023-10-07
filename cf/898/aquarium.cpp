#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    int arr[n];
    int num_blocks = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        num_blocks += arr[i];
    }

    sort(arr, arr+n);
    num_blocks -= arr[n-1];
    int area = arr[n-1] * (n-1);
    area -= num_blocks;
    int idx = n-1;
    while (area > x) {
        idx--;
        num_blocks -= arr[idx];
        area = arr[idx] * idx - num_blocks;
    }
    int remainder = x - area;
    //cout << remainder << endl;
    cout << arr[idx] + remainder / (idx + 1) << endl;

}

int main() {
    //freopen("aquarium.in", "r", stdin);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();
}