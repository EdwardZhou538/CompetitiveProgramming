#include <bits/stdc++.h>

using namespace std;

int main() {
        //freopen("aa.in", "r", stdin);
        map<int, int> a;

        int q;
        cin >>  q;

        for (int i = 0; i < q; i++) {
            int query;
            cin >> query;
            if (query == 0) {
                int v1, v2;
                cin >> v1 >> v2;

                a[v1] = v2;
            }
            if (query == 1) {
                int v;
                cin >> v;

                if (a.count(v) == 1) {
                    cout << a[v] << endl;
                }
                else cout << 0 << endl;
            }
        }
        return 0;
}