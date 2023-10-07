#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a+b < b+a;
}

int main() {
    //freopen("concat.in", "r", stdin);
    int n;
    cin >> n;

    string stuff[n];

    for (int i = 0; i < n; i++) {
        cin >> stuff[i];
    }

    sort(stuff, stuff + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << stuff[i];
    }

}