#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int weights[n];

    for (int i = 0; i < n; i++) cin >> weights[i];

    sort(weights, weights + n);

    int idx = 0;
    int num_unique = 0;

    while (idx < n-1 && weights[idx] < weights[idx + 1]) idx++;
    idx++;
    if (weights[idx] != idx + 1) num_unique += idx + 1;
    else num_unique += idx;

    while (weights[idx] == weights[idx + 1]) idx++;

    while (idx < )

}