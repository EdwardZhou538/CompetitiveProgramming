#include <bits/stdc++.h>

using namespace std;

void solve (int test) {
    int n; cin >> n;
    long long size[2*n-1];
    cout << "asdf" << endl;
    for (int i = 0; i < 2*n-1; i++) {
        cin >> size[i];
    }
    if (n == 1) {
        cout << "Case #" << test << ": " << size[0] << endl;
        return;
    }

    sort(size, size + 2*n-1);
    long long missing_apple = LLONG_MAX;
    long long case_1 = size[0] + size[2*n-3];
    bool true_1 = true;
    long long case_2 = size[1] + size[2*n-2];
    bool true_2 = true;
    long long case_3 = size[0] + size[2*n-2];
    bool true_3 = true;

    for (int i = 0; i < n - 1; i++) {
        if (size[i] + size[2*n-3-i] != case_1) {
            true_1 = false;
            break;
        }
    }
    if (true_1) {
        long long valid_apple = case_1 - size[2*n-2];
        if (valid_apple <= 0) true_1 = false;
        else {
            cout << "Case #" << test << ": " << valid_apple << endl;
            return;
        }
    }
    for (int i = 1; i < n; i++) {
        if (size[i] + size[2*n-1-i] != case_2) {
            true_2 = false;
            break;
        }
    }
    if (true_2) {
        missing_apple = case_2 - size[0];
    }
    int l = 0;
    int r = 2*n-2;
    bool already_pivoted = false;
    int missing_idx = -1;
    while (l < r) {
        if (size[l] + size[r] != case_3) {
            if (already_pivoted) {
                true_3 = false;
                break;
            }
            else {
                already_pivoted = true;
                if (size[l] + size[r] > case_3) missing_idx = r--;
                else missing_idx = l++;
            }
        }
        else {
            l++;
            r--;
        }
        
    }
    if (!already_pivoted) missing_idx = l;
    if (true_3) {
        missing_apple = case_3 - size[missing_idx];
    }
    if (!true_1 && !true_2 && !true_3) {
        cout << "Case #" << test << ": " << -1 << endl;
    }
    else cout << "Case #" << test << ": " << missing_apple << endl;
    return;

}

int main() {
    freopen("apples.in", "r", stdin);
    freopen("apples.txt", "w", stdout);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}