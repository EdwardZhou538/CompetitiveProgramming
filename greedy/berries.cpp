#include <bits/stdc++.h>

using namespace std;
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("berries.in");
    fout.open("berries.out");
    int n, k; fin >> n >> k;
    int trees[n];
    for (int i = 0; i < n; i++) fin >> trees[i];
    sort(trees, trees+n, cmp);

    int num_berries = 1;
    while(true) {
        int num_baskets = k;
        for (int i = 0; i < n; i++) {
            if (num_baskets <= 0 || trees[i] < num_berries) break;
            num_baskets -= trees[i]/num_berries;
        }
        if (num_baskets > 0) {
            num_berries--;
            break;
        }
    }
    int num_extra = 0;
    int baskets_filled = 0;
    for (int i = 0; i < n; i++) {
        int used_baskets = min(k-baskets_filled, )
    }
}