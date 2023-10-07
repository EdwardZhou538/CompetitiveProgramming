#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second


int main() {
    //freopen("closest.in", "r", stdin);

    int k, m, n;
    cin >> k >> m >> n;

    pair<int, int> patches[k];
    for (int i = 0; i < k; i++) {
        cin >> patches[i].f >> patches[i].s;
    }
    sort(patches, patches+k);

    int nhoj[m];
    for (int i = 0; i < m; i++) cin >> nhoj[i];

    sort(nhoj, nhoj + m);

    long long values[m*2];

    for (int i = 0; i < 2*m; i++) values[i] = 0;

    int idx = 0;
    while (patches[idx].f < nhoj[0]) {
        values[0] += patches[idx].s;
        idx++;
    }
    if (patches[idx].f == nhoj[0]) idx++;
    int l = idx;
    int r = idx;
    for (int i = 0; i < m-1; i++) {
        int total_val = 0;
        int one_val = 0;
        int one_max = 0;
        while (r < k && patches[r].f < nhoj[i+1]) {
            total_val += patches[r].s;
            one_val += patches[r].s;
            r++;
            while (patches[r-1].f - patches[l].f > (nhoj[i+1] - nhoj[i] - 2) / 2) {
                one_val -= patches[l].s;
                l++;
                
            }
            one_max = max(one_max, one_val);
        }
        values[i*2+1] = one_max;
        values[i*2+2] = total_val - one_max;
        if (r == k) break;
        if (patches[r].f == nhoj[i+1]) r++;
        l = r;
    }
    while (r < k) {
        values[2*m-1] += patches[r].s;
        r++;
    }
    sort(values, values+2*m);

    long long max_tastiness = 0;
    for (int i = 0; i < n; i++) {
        max_tastiness += values[2*m-i-1];
    }
    cout << max_tastiness;
    return 0;
}