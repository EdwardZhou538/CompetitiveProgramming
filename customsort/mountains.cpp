#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second - a.first > b.second - b.first) return true;
    else if (a.second - a.first == b.second - b.first && a.second > b.second) return true;
    else return false;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("mountains.in");
    fout.open("mountains.out");
    int n;
    fin >> n;

    pair<int, int> peaks[n];

    for (int i = 0; i < n; i++) {
        fin >> peaks[i].first >> peaks[i].second;
    }

    sort(peaks, peaks + n, cmp);

    /*for (int i = 0; i < n; i++) {
        cout << peaks[i].first << " " << peaks[i].second << endl;
    }*/
    int num_peaks = 1;

    int idx = 0;
    while (idx < n) {
        int peak = idx;
        idx += 1;
        while (idx < n && peaks[peak].second - peaks[idx].second >= abs(peaks[peak].first - peaks[idx].first)) idx++;
        if (idx < n) {
            num_peaks++;
            peak = idx;
        }
        //cout << idx << endl;
    }
    fout << num_peaks;

    fin.close();
    fout.close();

    return 0;

}