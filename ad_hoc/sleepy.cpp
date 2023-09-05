#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    fin.open("sleepy.in");
    fout.open("sleepy.out");

    int n;
    fin >> n;
    int order[n];
    for (int i = 0; i < n; i++) fin >> order[i];

    int num_sorted = 1;
    for (int i = n-1; i > 0; i--) {
        if (order[i] < order[i-1]) {
            break;
        }
        num_sorted++;
    }
    fout << n - num_sorted;
    fin.close();
    fout.close();
    return 0;
}