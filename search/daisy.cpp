#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;

    int daisies[n];

    for (int i = 0; i < n; i++) {
        cin >> daisies[i];
    }

    int num_avg = n;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int total = 0;
            for (int k = i; k <= j; k++) {
                total += daisies[k];
            }
            for (int k = i; k <= j; k++) {
                if (daisies[k]*(j-i+1) == total) {
                    num_avg++;
                    break;
                }
            }
        }
    }

    cout << num_avg;
}