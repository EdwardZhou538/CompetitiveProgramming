#include <iostream>
using namespace std;

int main() {
    freopen("abbc.in", "r", stdin);
    int t; cin >> t;
    string s; cin >> s;
    int num_a = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'A') num_a++;
    }
    cout << num_a << endl;
    return 0;
}