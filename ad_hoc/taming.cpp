#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("taming.in");
    fout.open("taming.out");
    int n;
    fin >> n;
    int days[n];

    for (int i = 0; i < n; i++) {
        fin >> days[i];
    }

    int min_breakouts = 0;
    int max_breakouts = 0;
    int current_day = n-1;
    while (current_day >= 0) {
        if (days[current_day] == -1) {
            max_breakouts++;
            current_day--;
        }
        else {
            current_day -= days[current_day] + 1;
            max_breakouts++;
            min_breakouts++;
        }
    }

    bool wtf = false;
    for (int i = 0; i < n; i++) {
        if (days[i] != -1) {
            if (days[i] != i) min_breakouts++;
            wtf = true;
            break;
        }
    }
    if (!wtf) min_breakouts++;
    fout << min_breakouts << " " << max_breakouts;
    fin.close();
    fout.close();
    return 0;
}