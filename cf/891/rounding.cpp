#include <bits/stdc++.h>

using namespace std;

void solve() {
    string x;
    cin >> x;
    int len = x.length();
    int digits[len];
    
    for (int i = 0; i < x.length(); i++) {
        digits[i] = int(x.at(i)) - 48;
    }

    for (int i = len - 1; i > 0; i--) {
        if (digits[i] < 5) continue;
        else {
            digits[i-1]++;
            for (int j = i; j < len; j++) {
                digits[j] = 0;
            }
        }
    }
    if (digits[0] >= 5) {
        cout << "1";
        for (int i = 0; i < len; i++) cout << "0";
        cout << endl;
    }
    else {
        for(int i = 0; i < len; i++) cout << digits[i];
        cout << endl;
    }
}

int main() {
    //freopen("rounding.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}