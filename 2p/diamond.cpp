#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("diamond.in");
    fout.open("diamond.out");
    int n, k; fin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) fin >> arr[i];

    sort(arr, arr+n);
    int l = 0, r = 1;

    int max_diamonds = 0;
    int max_l = 0;

    for (int i = 0; i < n-1; i++) {
        while(arr[i] - arr[l] > k) l++;
        max_l = max(max_l, i-l+1);
        while (r < n && arr[r] - arr[i+1] <= k) {
            r++;
        }
        max_diamonds = max(max_diamonds, max_l + r-i-1);
    }
    fout << max_diamonds;
    fin.close();
    fout.close();
    return 0;
}