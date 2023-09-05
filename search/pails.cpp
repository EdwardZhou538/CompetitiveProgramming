#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("pails.in");
    int x;
    int y;
    int m;
    fin >> x >> y >> m;
    int big_pail = max(x, y);
    int small_pail = min(x, y);
    int num_big_dumps = 0;
    int capacity = 0;
    int max_capacity = 0;


    capacity += big_pail * (m/big_pail);
    num_big_dumps += m/big_pail;


    capacity += small_pail * ((m - capacity) / small_pail);
    max_capacity = capacity;

    while (num_big_dumps > 0) {
        capacity -= big_pail;
        num_big_dumps--;

        capacity += small_pail * ((m - capacity) / small_pail);
        max_capacity = max(max_capacity, capacity);

    }
    fout.open("pails.out");
    fout << max_capacity;
    fin.close();
    fout.close();
    return 0;
}