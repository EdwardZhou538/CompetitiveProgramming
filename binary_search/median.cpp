#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("median.in", "r", stdin);

    int n, k; cin >> n >> k;

    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int m = n/2;
    int r = m+1;
    while (r < n) {
        if (k < (r-m)*(arr[r]-arr[r-1])) {
            cout << arr[r-1] + k/(r-m);
            break;
        }
        k -= (r-m)*(arr[r]-arr[r-1]);
        r++;
    }
    if (r == n) {
        cout << arr[r-1] + k/(r-m);
    }
    return 0;
}