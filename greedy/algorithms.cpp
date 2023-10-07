#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("algorithms.in", "r", stdin);
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
        if (total > x) {
            cout << i;
            break;
        }
    }
    if (total <= x) cout << n;
    return 0;   
}