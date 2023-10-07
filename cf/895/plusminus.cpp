#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

void solve() {
    long long n, x, y;

    cin >> n >> x >> y;

    long long num_x = n/x, num_y = n/y;

    long long num_same = n/lcm(x, y);

    num_x -= num_same;
    num_y -= num_same;

    //cout << n << " " << num_x << " " << num_y << " " << num_same << endl;

    long long greatest_total = n*num_x - (num_x)*(num_x - 1)/2 - num_y * (num_y + 1)/2;

    /*for (long long i = 0 ; i < num_x; i++) {
        greatest_total += n-i;
        //cout << greatest_total << endl;
    }

    for (long long i = 0; i < num_y; i++) {
        greatest_total -= i + 1;
        //cout << greatest_total << endl;
    }*/

    cout << greatest_total << endl;
}

int main() {
    //freopen("plusminus.in", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}