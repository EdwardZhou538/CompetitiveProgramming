#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("herding.in");
    fout.open("herding.out");

    int n; fin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) fin >> arr[i];

    sort(arr, arr+n);
    int l = 0, r = 0;
    int min_steps =  INT_MAX;
    while (l < n) {
        while (r < n && arr[r] - arr[l] < n) {
            r++;
        }
        min_steps = min(min_steps, n-r+l);
        if (r == n) l = n;
        else {
            while(arr[r] - arr[l] >= n) l++;
        }
    }


    if (arr[n-2] - arr[0] == n-2 && arr[n-1] - arr[n-2] > 2) min_steps = 2;

    if (arr[n-1] - arr[1] == n-2 && arr[1] - arr[0] > 2) min_steps = 2;
    l = 0;
    r = n-1;
    int gap = min(arr[l+1] - arr[l], arr[r] - arr[r-1]);
    int max_steps = arr[r] - arr[l] - n + 2 - gap;
    fout << min_steps << endl;
    fout << max_steps << endl;
    fin.close();
    fout.close();
    return 0;

}