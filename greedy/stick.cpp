#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    long long lengths[n];
    for (int i = 0; i < n; i++) cin >> lengths[i];
    sort(lengths, lengths + n);
    long long min_length = 0;
    for (int i = 0; i < n; i++) {
        min_length += abs(lengths[i] - lengths[n/2]);
    }
    cout << min_length;
    return 0;
}