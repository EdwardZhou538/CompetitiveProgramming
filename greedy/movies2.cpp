#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    //freopen("movies2.in", "r", stdin);

    int n, k; cin >> n >> k;
    pair<int, int> times[n];
    for (int i = 0; i < n; i++) {
        cin >> times[i].first >> times[i].second;
    }

    sort(times, times + n, cmp);

    multiset<int> ms;
    int num_movies = 0;
    for (int i = 0; i < n; i++) {
        if (ms.empty()) {
            ms.insert(-times[i].second);
            num_movies++;
        }
        else if (ms.lower_bound(-times[i].first) != ms.end()) {
            ms.erase(ms.find(*ms.lower_bound(-times[i].first)));
            ms.insert(-times[i].second);
            num_movies++;
        }
        else if ((int)ms.size() < k) {
            ms.insert(-times[i].second);
            num_movies++;
        }
    }
    cout << num_movies;
    return 0;
}