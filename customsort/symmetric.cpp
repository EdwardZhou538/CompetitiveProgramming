#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long arr[2*n];
    for (int i = 0; i < 2*n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 2*n);
    /*for (int i = 0; i < 2*n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    long long cumsum = 0;
    for (int i = n-1; i >= 0; i--) {
        if (arr[2*i] != arr[2*i + 1] || (arr[2*i] - cumsum) % (2*(i+1)) != 0 || arr[2*i] - cumsum <= 0) {
            cout << "NO" << endl;
            return;
        }
        if (i < n-1 && arr[2*i] == arr[2*i+2]) {
            cout << "NO" << endl;
            return;
        }
        cumsum += (arr[2*i] - cumsum) / (i + 1);

    }
    cout << "YES" << endl;
    return;
}

int main() {
    //freopen("symmetric.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}