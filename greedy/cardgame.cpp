#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("cardgame.in");
    fout.open("cardgame.out");
    int n; fin >> n;

    int elsie_first[n/2];
    int elsie_second[n/2];
    unordered_set<int> numbers;
    for (int i = 1; i <= 2*n; i++) numbers.insert(i);

    for (int i = 0; i < n/2; i++) {
        fin >> elsie_first[i];
        numbers.erase(elsie_first[i]);
    }

    for (int i = 0; i < n/2; i++) {
        fin >> elsie_second[i];
        numbers.erase(elsie_second[i]);
    }

    int bessie_cards[n];
    int idx = 0;
    for (const auto& elem: numbers) {
        bessie_cards[idx] = elem;
        idx++;
    }
    sort(bessie_cards, bessie_cards + n, cmp);
    sort(bessie_cards, bessie_cards+n/2);
    sort(elsie_first, elsie_first + n/2);
    sort(elsie_second, elsie_second + n/2, cmp);
    
    int bessie_idx = 0;
    int elsie_idx = 0;
    int num_points = 0;
    while (elsie_idx < n/2) {
        while (bessie_idx < n/2 && bessie_cards[bessie_idx] < elsie_first[elsie_idx]) bessie_idx++;
        if (bessie_idx == n/2) break;
        num_points++;
        bessie_idx++;
        elsie_idx++;
    }
    elsie_idx = 0;
    bessie_idx = n/2;
    while(elsie_idx < n/2) {
        while (bessie_idx < n && bessie_cards[bessie_idx] > elsie_second[elsie_idx]) bessie_idx++;
        if (bessie_idx == n) break;
        num_points++;
        bessie_idx++;
        elsie_idx++;
    }
    fout << num_points;
    fin.close();
    fout.close();
    return 0;
}