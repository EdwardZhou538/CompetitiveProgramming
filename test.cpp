#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    cout << *s.lower_bound(3) << endl;
    if (s.lower_bound(6) == s.end()) cout << "POG" << endl;
    return 0;
}