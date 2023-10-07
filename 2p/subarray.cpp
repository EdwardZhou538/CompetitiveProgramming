#include <bits/stdc++.h>

using namespace std;

int main() {
    //xfreopen("subarray.in", "r", stdin);

    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = 0;
    int num_subs = 0;
    int sub_sum = 0;
    while (l < n) {
        while(sub_sum < x && r < n) {
            sub_sum += arr[r];
            r++;
        }
        if (sub_sum == x) num_subs++;
        else if (sub_sum < x) break;
        sub_sum -= arr[l];
        l++;
    }
    cout << num_subs;
}