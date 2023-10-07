#include <bits/stdc++.h>

using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(1);                  // [1]
    ms.insert(14);                 // [1, 14]
    ms.insert(9);                  // [1, 9, 14]
    ms.insert(2);                  // [1, 2, 9, 14]
    ms.insert(9);                  // [1, 2, 9, 9, 14]
    ms.insert(9);                  // [1, 2, 9, 9, 9, 14]
    cout << ms.count(4) << '\n';   // 0
    cout << ms.count(9) << '\n';   // 3
    cout << ms.count(14) << '\n';  // 1
    ms.erase(ms.find(9));
    cout << ms.count(9) << '\n';  // 2
    /*ms.erase(9);
    cout << ms.count(9) << '\n';  // 0*/

    auto i = ms.end();
    cout << *(--i) << endl;
    ms.erase(14);
    i = ms.end();
    cout << *(--i) << endl;
    return 0;
}