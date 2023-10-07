#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("helpcross.in");
    fout.open("helpcross.out");

    int c, n; fin >> c >> n;
    multiset<int> chicken;
    for (int i = 0; i < c; i++) {
        int a; fin >> a;
        chicken.insert(a);
    }
    pair<int, int>cows[n];
    for (int i = 0; i < n; i++) {
        fin >> cows[i].first >> cows[i].second;
    }

    sort(cows, cows+n, cmp);
    int num_pairs = 0;
    for (int i = 0; i < n; i++) {
        auto pt = chicken.lower_bound(cows[i].first);
        if (pt == chicken.end() || *pt > cows[i].second) continue;
        num_pairs++;
        chicken.erase(chicken.find(*pt));
    }
    fout << num_pairs;
    fin.close();
    fout.close();
    return 0;
}