#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("traffic.in");
    fout.open("traffic.out");

    int n;
    fin >> n;
    vector< tuple<string, int, int> > snapshots;

    for (int i = 0; i < n; i++) {
        string status;
        int min_cars;
        int max_cars;
        fin >> status >> min_cars >> max_cars;
        snapshots.push_back( tuple<string, int, int>(status, min_cars, max_cars));
    }

    int min_end = 0;
    int max_end = 10000;
    int min_start = 0;
    int max_start = 10000;

    for (int i = 0; i < n; i++) {
        if (get<0>(snapshots[i]) == "on") {
            min_end += get<1>(snapshots[i]);
            max_end += get<2>(snapshots[i]);
        }
        else if (get<0>(snapshots[i]) == "off") {
            min_end -= get<2>(snapshots[i]);
            max_end -= get<1>(snapshots[i]);
        }
        else {
            min_end = max(min_end, get<1>(snapshots[i]));
            max_end = min(max_end, get<2>(snapshots[i]));
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (get<0>(snapshots[i]) == "off") {
            min_start += get<1>(snapshots[i]);
            max_start += get<2>(snapshots[i]);
        }
        else if (get<0>(snapshots[i]) == "on") {
            min_start -= get<2>(snapshots[i]);
            max_start -= get<1>(snapshots[i]);
        }
        else {
            min_start = max(min_start, get<1>(snapshots[i]));
            max_start = min(max_start, get<2>(snapshots[i]));
        }
    }
    fout << max(0, min_start) << " " << max_start << endl;
    fout << max(0, min_end) << " " << max_end << endl;
    fin.close();
    fout.close();
    return 0;
}