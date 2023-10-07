#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("pairup.in");
    fout.open("pairup.out");

    int n;
    fin >> n;

    pair<int, int> cows[n];
    for (int i = 0; i < n; i++) {
        fin >> cows[i].first >> cows[i].second;
    }

    int l = 0, r = n-1;
    int min_time = 0;
    sort(cows, cows+n, cmp);

    while (l <= r) {
        min_time = max(min_time, cows[l].second + cows[r].second);
        if (l < r) {
            if (cows[l].first < cows[r].first) {
                cows[r].first -= cows[l].first;
                l++;
            }
            else if (cows[l].first > cows[r].first) {
                cows[l].first -= cows[r].first;
                r--;
            }
            else {
                l++;
                r--;
            }
        }
        else l++;
    }
    fout << min_time;
    fin.close();
    fout.close();
    return 0;
}