#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("towers.in", "r", stdin);

    multiset<int> ms;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int block; cin >> block;
        if (ms.upper_bound(block) == ms.end()) ms.insert(block);
        else {
            ms.erase(ms.find(*ms.upper_bound(block)));
            ms.insert(block);
        }
    }
    cout << ms.size() << endl;
}