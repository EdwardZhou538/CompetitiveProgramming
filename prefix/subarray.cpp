#include <bits/stdc++.h>

using namespace std;
int main() {
    //freopen("subarray.in", "r", stdin);

    long long n, x;
    cin >> n >> x;

    long long psum[n+1];
    psum[0] = 0;
    for (int i = 1; i <=n; i++) {
        long long k;
        cin >> k;
        psum[i] = psum[i-1] + k;
    }
    
    int num_subarrays = 0;

    for (int i = 0; i<=n; i++) {
        for (int j = i+1; j<=n; j++) {
            if (psum[j] - psum[i] == x) num_subarrays++;
        }
    }
    cout << num_subarrays;
    return 0;
}