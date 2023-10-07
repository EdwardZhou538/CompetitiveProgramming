#include <bits/stdc++.h>

using namespace std;

long long fastmod(long long a, long long b) {
    return (a >= b) ? a % b : a;
}

long long factorial(long long n) {
    long long total = 1;
    for (long long i = 1; i <= n; i++) {
        total = fastmod(total * i, (long long)998244353);
    }
    return total;
}


void solve() {
    string s; cin >> s;
    char current = s.at(0);
    int block_len = 0;
    int num_removals = 0;
    long long num_sequences = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) != current) {
            num_removals += block_len - 1;
            num_sequences = fastmod(num_sequences * block_len, (long long)998244353);
            current = s.at(i);
            block_len = 1;
        }
        else block_len++;
    }
    num_removals += block_len - 1;
    num_sequences = fastmod(num_sequences * block_len, (long long)998244353);
    num_sequences *= factorial(num_removals);
    cout << num_removals << " " << fastmod(num_sequences, (long long)998244353) << endl;
}

int main() {
    //freopen("alternate.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}