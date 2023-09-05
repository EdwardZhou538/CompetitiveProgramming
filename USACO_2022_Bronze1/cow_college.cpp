#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long maxTuition[n];
    for (int i = 0; i < n; i++) {
        cin >> maxTuition[i];
    }
    
    sort(maxTuition, maxTuition + n);
    
    long long tuition = maxTuition[0];
    long long total = tuition * n;
    for (int i = 1; i < n; i++) {
        if (maxTuition[i] == maxTuition[i-1]) {
            continue;
        }
        if (maxTuition[i] * (n - i) > total) {
            total = maxTuition[i] * (n - i);
            tuition = maxTuition[i];
        }
    }

    cout << total << " " << tuition;

    return 0;
}