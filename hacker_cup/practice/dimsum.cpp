#include <bits/stdc++.h>
using namespace std;

void solve(int test) {
    int r, c; cin >> r >> c;
    int a, b; cin >> a >> b;
    /*int alice_turn[r][c];
    int bob_turn[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            alice_turn[i][j] = 0;
            bob_turn[i][j] = 1;
        }
    }
    for (int i = 0; i < r-1; i++) {
        alice_turn[i][c-1] = 1;
    }
    for (int i = 0; i < c-1; i++) {
        bob_turn[r-1][i] = 0;
    }
    for (int i = r-2; i>=0; i--) {
        for (int j = c-2; j >=0; j--) {
            for (int k = 1; k < min(a+1, r-i); k++) {
                if (bob_turn[i+k][j] == 1) {
                    alice_turn[i][j] = 1;
                    break;
                }
            }
            for (int k = 1; k < min(b+1, c-j); k++) {
                if (alice_turn[i][j+k] == 0) {
                    bob_turn[i][j] = 0;
                    break;
                }
            }
        }
    }*/
    string result = (r > c) ? "YES" : "NO";
    /*cout << result << endl;
    for (int i = 0; i< r; i++) {
        for (int j = 0; j < c; j++) {
            cout << alice_turn[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << "Case #" << test << ": " << result << endl;
    //printf("Case #%d: %s\n", test, result);
}

int main() {
    freopen("dimsum.in", "r", stdin);
    freopen("dimsum.txt", "w", stdout);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}