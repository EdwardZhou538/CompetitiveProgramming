#include <bits/stdc++.h>

using namespace std;

int last_valid(int l, int r, function<bool(int)> f) {
    while (l < r) {
        int m = l + (r-l)/2;
        if (f(m)) r = m;
        else l = m+1;
    }
    return l;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("angry.in");
    fout.open("angry.out");
    int n, k;
    fin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }
    sort(arr, arr+n);

    fout << last_valid(1, arr[n-1] - arr[0], [&](int x) {
        int idx = 0;
        for (int i = 0; i < k; i++) {
            int cow_1 = arr[idx] + x;
            while (arr[idx] <= cow_1 + x) {
                idx++;
                if (idx == n) return true;
            }
        }
        return false;
    });
    fin.close();
    fout.close();
    return 0;
}