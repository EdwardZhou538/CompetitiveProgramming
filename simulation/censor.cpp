#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    fin.open("censor.in");
    string s, t;

    fin >> s;
    fin >> t;
    bool in_s[s.size()];

    for (int i = 0; i < s.size(); i++) {
        in_s[i] = true;
    }

    while(true) {
        int idx = 0;

        while (idx < s.size()) {
            if(!in_s[i]) {
                idx++;
                continue;
            }

            if (s.at(i) == t.at(0)) {
                for (int i = 0; i < t.size(); i++) {
                    if 
                }
            }
        }
    }
}