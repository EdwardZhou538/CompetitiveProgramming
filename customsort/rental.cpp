#include <bits/stdc++.h>

using namespace std;

bool cmp1(int a, int b) {
    return a > b;
}
bool cmp2(pair<long long, long long> p1, pair<long long, long long> p2) {
    return p1.second > p2.second;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("rental.in");
    fout.open("rental.out");

    int n, m, r;

    fin >> n >> m >> r;
    int milk[n];
    pair<long long, long long> buyers[m];
    int renters[r];

    for (int i = 0; i < n; i++) {
        fin >> milk[i];
    }

    for (int i = 0; i < m; i++) {
        int amt, cost;
        fin >> buyers[i].first >> buyers[i].second;
    }

    for (int i = 0; i < r; i++) {
        fin >> renters[i];
    }

    sort(milk, milk + n, cmp1);
    sort(buyers, buyers + m, cmp2);
    sort(renters, renters+r, cmp1);

    long long money[n];
    long long total = 0;
    int current_buyer = 0;
    for (int i = 0; i < n; i++) {
        money[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (current_buyer == m) break;
        while (milk[i] > 0) {
            while (buyers[current_buyer].first < milk[i]) {
                money[i] += buyers[current_buyer].first * buyers[current_buyer].second;
                milk[i] -= buyers[current_buyer].first;
                current_buyer++;
                if (current_buyer == m) break;
            }
            if (current_buyer == m) break;
            money[i] += buyers[current_buyer].second * milk[i];
            buyers[current_buyer].first -= milk[i];
            if (buyers[current_buyer].first == 0) current_buyer++;
            milk[i] = 0;
        }
        total += money[i];
        //cout << money[i] << endl;
    }


    for (int i = 0; i < r; i++) {
        if (i == n) break;
        if (renters[i] < money[n-i-1]) break;
        total += renters[i] - money[n-i-1];
    }
    fout << total;
    fin.close();
    fout.close();
    return 0;
    
}