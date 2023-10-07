#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("deadlines.in", "r", stdin);
    int n; cin >> n;
    pair<long long, long long> tasks[n];
    for (int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;

    sort(tasks, tasks+n);
    long long finish[n];
    finish[0] = tasks[0].first;
    for (int i = 1; i < n; i++) finish[i] = finish[i-1] + tasks[i].first;
    long long max_reward = 0;
    for (int i = 0; i < n; i++) max_reward += tasks[i].second - finish[i];
    cout << max_reward;
    return 0;
}