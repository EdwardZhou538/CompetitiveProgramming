#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("books.in", "r", stdin);

    int n, t;
    cin >> n >> t;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int total = 0;
    bool stopped = true;
    for (int i = 0; i < n; i++) {
        total += arr[i];
        if (total > t) {
            cout << i;
            stopped = false;
            break;
        }
    }

    if (stopped) cout << n;
    return 0;
}