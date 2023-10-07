#include <bits/stdc++.h>

using namespace std;
int main() {
    //freopen("traffic.in", "r", stdin);

    int x, n; cin >> x >> n;
    set<int> pos;
    pos.insert(0);
    pos.insert(x);
    multiset<int> gap;
    gap.insert(x);
    for (int i = 0; i < n; i++) {
        int light;
        cin >> light;
        pos.insert(light);
        auto greater = pos.upper_bound(light);
        int upper_bound = *(greater--);
        int lower_bound = *(--greater);
        gap.erase(gap.find(upper_bound - lower_bound));
        gap.insert(upper_bound - light);
        gap.insert(light - lower_bound);
        auto greatest_distance = gap.end();
        cout << *(--greatest_distance) << " ";

        /*int 
        int lesser = 
        gap.erase(*greater - *(greater-2));
        gap.insert(*greater- *(greater-1));
        gap.insert(*(greater-1) - *(greater-2));
        auto greatest_distance = gap.end();
        cout << *(--greatest_distance) << " ";*/
    }
    return 0;
}