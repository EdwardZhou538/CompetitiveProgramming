#include <bits/stdc++.h>

using namespace std;
int main() {
    //freopen("pokemon.in", "r", stdin);

    int n;
    cin >> n;

    map<char, int> counter;
    set<char> unique;
    string pokemon;
    cin >> pokemon;

    for (int i = 0;  i < n; i++) {
        unique.insert(pokemon.at(i));
    }

    int l = 0, r = -1;

    int min_length = INT_MAX;

    while (l< n) {
        while (r < n) {
            r++;
            if (r == n) break;
            if (counter.count(pokemon.at(r)) != 1) {
                counter[pokemon.at(r)] = 1;
                if (counter.size() == unique.size()) {
                    min_length = min(min_length, r-l+1);
                    break;
                }
            }
            else {
                counter[pokemon.at(r)]++;
                if (counter[pokemon.at(r)] == 1) {
                    min_length = min(min_length, r-l+1);
                    break;
                }
            }
        }
        if (r == n) break;
        while(true) {
            counter[pokemon.at(l)]--;
            if (counter[pokemon.at(l)] == 0) {
                l++;
                break;
            }
            else {
                l++;
                min_length = min(min_length, r-l+1);
            }
        }
    }
    cout << min_length;
    return 0;
}