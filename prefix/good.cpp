#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long psum[n+1];
    psum[0] = 0;
    string digits;
    cin >> digits;
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + int(digits.at(i-1))-48;
    }

    map<long long, long long> counter;

    for (long long i = 0; i <= n; i++) {
        psum[i] -= i;
        if (counter.count(psum[i]) == 1) counter[psum[i]]++;
        else counter[psum[i]] = 1;
    }
    long long num_good = 0;

    for (auto num: counter) {
        num_good += num.second*(num.second-1)/2;
    }
    cout << num_good << endl;
}
int main() {
    //freopen("good.in", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}