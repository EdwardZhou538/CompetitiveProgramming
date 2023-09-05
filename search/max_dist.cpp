#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x[n];
    int y[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0 ; i < n; i++ ) {
        cin >> y[i];
    }

    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_dist = max(max_dist, int(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)));
        }
    }
    cout << max_dist;
    return 0;
}