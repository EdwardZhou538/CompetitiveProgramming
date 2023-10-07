#include <bits/stdc++.h>

using namespace std;

struct cow_log {
    int day;
    int cow;
    int change;
};

bool cmp(cow_log a, cow_log b) {
    return a.day < b.day;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("measurement.in");
    fout.open("measurement.out");

    int n, g; fin >> n >> g;

    cow_log logs[n];
    unordered_map<int, int> prod;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        fin >> logs[i].day >> logs[i].cow >> logs[i].change;
        if (prod.count(logs[i].cow) != 1) {
            prod[logs[i].cow] = g;
            ms.insert(g);
        }
    }
    sort(logs, logs+n, cmp);
    //for (int i = 0; i < n; i++) cout << logs[i].day << " " << logs[i].cow << " " << logs[i].change << endl;

    int num_changes = 0;
    ms.insert(g);

    for (int i = 0; i < n; i++) {
        auto max_val = ms.end();
        //cout << "Cow " << i << ": " << prod[logs[i].cow] << endl;
        if (prod[logs[i].cow] == *(--max_val)) {
            //cout << i << ": " << *max_val << endl;
            bool skip = false;
            if (ms.count(prod[logs[i].cow]) > 1) {
                num_changes++;
                //cout << "pogger" << endl;
                skip = true;
            }
            ms.erase(ms.find(prod[logs[i].cow]));
            prod[logs[i].cow] += logs[i].change;
            ms.insert(prod[logs[i].cow]);
            if (skip) continue;
            auto new_max = ms.end();
            if (prod[logs[i].cow] != *(--new_max)) {
                num_changes++;
                //cout << "a" << endl;
            }
            else if (ms.count(*new_max) > 1) {
                num_changes++;
                //cout << "B" << endl;
            }
        }
        else {
            ms.erase(ms.find(prod[logs[i].cow]));
            prod[logs[i].cow] += logs[i].change;
            //cout << prod[logs[i].cow] << " " ;
            ms.insert(prod[logs[i].cow]);
            auto new_max = ms.end();
            if (prod[logs[i].cow] == *(--new_max)) {
                num_changes++;
                //cout << "pog" << endl;
            }
        }
        //cout << *max_val << endl;
    }
    fout << num_changes;
    fin.close();
    fout.close();
    return 0;
}