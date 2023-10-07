#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("stacking.in");
    fout.open("stacking.out");

    int n, k;
    fin >> n >> k;

    int bales[n];
    for (int i = 0; i < n; i++) {
        bales[i] = 0;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        fin >> a >> b;

        for (int j = a; j <= b; j++) {
            bales[j]++;
        }
    }
    sort(bales, bales+n);

    fout << bales[n/2];
    fin.close();
    fout.close();
    return 0;
}