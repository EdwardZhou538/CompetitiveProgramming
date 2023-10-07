#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("concert.in", "r", stdin);
    int n, m; cin >> n >> m;
    multiset<int> prices;

    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.insert(-price);
    }
    for (int i = 0; i < m; i++) {
        int threshold;
        cin >> threshold;
        auto end = prices.end();
        if (prices.empty() || -threshold > *(--end)) cout << -1 << endl;
        else {
            int buy_price = *prices.lower_bound(-threshold);
            cout << -buy_price << endl;
            prices.erase(prices.find(buy_price));
        }
    }

    return 0;
}