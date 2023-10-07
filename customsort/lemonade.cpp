#include <bits/stdc++.h>

bool cmp(int a, int b) {
    return a >= b;
}

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    fin.open("lemonade.in");
    fout.open("lemonade.out");

    int n;
    fin >> n;
    int order[n];
    for (int i = 0; i < n; i++) fin >> order[i];

    sort(order, order + n, cmp);

    bool asdf = true;
    for (int i = 0; i < n; i++) {
        if (i > order[i]) {
            fout << i;
            asdf = false;
            break;
        }
    }

    if (asdf) fout << n;
    fin.close();
    fout.close();

    return 0;
}