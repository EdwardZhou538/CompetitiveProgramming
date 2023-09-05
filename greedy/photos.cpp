#include <bits/stdc++.h>

using namespace std;
int main() {
    //freopen("photos.in", "r", stdin);

    int n;
    cin >> n;
    int num_odd = 0;
    int num_even = 0;

    for (int i = 0 ; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1) num_odd++;
        else num_even++;
    }

    if (num_odd <= num_even) cout << num_odd*2 + 1;
    else {
        int diff = num_odd - num_even;
        if (diff == 1) cout << num_even*2-1;
        else if (diff % 3 == 1) cout << num_even*2 + (diff-4)*2/3+1;
        else cout << num_even*2 + diff*2/3;
    }
}