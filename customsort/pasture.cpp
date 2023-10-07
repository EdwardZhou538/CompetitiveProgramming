#include <bits/stdc++.h>

using namespace std;

struct point {
    int x;
    int y;
}

bool cmp(point a, point b) return a.x < b.x;

int main() {
    freopen("pasture.in", "r", stdin);

    int n;
    cin >> n;

    point location[n];

    for (int i = 0; i < n; i++) {
        cin >> location[i].x >> location[i].y;
    }

    sort(location, location+n, cmp);

    long long total = 0;

    long long psum[n+1][2];
    psum[0][0] = 0;
    psum[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        
    }
}