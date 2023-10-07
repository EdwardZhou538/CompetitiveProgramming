#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("cellular.in", "r", stdin);

    int n, m;
    cin >> n >> m;

    int cities[n];

    int towers[m];

    for (int i = 0; i < n; i++) cin >> cities[i];
    for (int i = 0; i < m; i++) cin >> towers[i];


    int cp = 0;
    int tp = 0;

    int min_dist = 0;
    if (cities[cp] < towers[tp]) min_dist = towers[tp] - cities[cp];

    while (cities[cp] < towers[tp]) cp++;

    while(tp < m-1 && towers[tp+1] < cities[cp]) tp++;

    while (cp < n) {
        if (tp == m-1) {
            min_dist = max(min_dist, cities[cp] - towers[tp]);
            cp++;
        }
        else {
            min_dist = max(min_dist, min(cities[cp] - towers[tp], towers[tp+1] - cities[cp]));
            cp++;
            while (tp < m-1 && cities[cp] > towers[tp+1]) tp++;
        }
    }

    cout << min_dist;
    return 0;
}