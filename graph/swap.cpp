#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    fin.open("swap.in");
    fout.open("swap.out");
    int n, k;
    fin >> n >> k;

    int order[n];
    for (int i = 0; i < n; i++) {
        order[i] = i + 1;
    }
    int a1, a2, b1, b2;

    fin >> a1 >> a2 >> b1 >> b2;
    a1--;
    a2--;
    b1--;
    b2--;

    if (a1 == b1 && a2 == b2) k = 0;
    else if (a2 < b1 || b2 < a1) k %= 2;
    else if ((a1 >= b1 && a2 <= b2) || b1 >= a1 && b2 <= a2) k %= 2;
    else {
        int intersect_length = 2 * (min(a2-b1, b2-a1) + 1);
        if (intersect_length > a1 && intersect_length > b1) k %= 5;
        else if (intersect_length <= a1 && intersect_length <= b1) k %= 3;
        else k %= 6;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (a2 - a1 + 1)/2; j++) {
            swap(order[a1 + j], order[a2 - j]);
        }
        for (int j = 0; j < (b2 - b1 + 1)/2; j++) {
            swap(order[b1 + j], order[b2 - j]);
        }
    }
    

    for (int i = 0; i < n; i++) {
        fout << order[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}