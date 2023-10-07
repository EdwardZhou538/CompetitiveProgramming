#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("cowdance.in");
    fout.open("cowdance.out");
    int n, t; fin >> n >> t;
    int cows[n];
    for (int i = 0; i < n; i++) fin >> cows[i];
    priority_queue<int> pq;
    int l = 0;
    int r = n-1;
    int m = l + (r - l + 1) / 2;
    while (l < r) {
        m = l + (r - l - 1) / 2;
        int time = 0;
        priority_queue<int> pq;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (i < m+1) {
                pq.push(-cows[i]);
                time = max(time, cows[i]);
            }
            else {
                int val = -pq.top();
                pq.pop();
                pq.push(-val-cows[i]);
                time = max(time, val + cows[i]);
            }
            if (time > t) {
                valid = false;
                break;
            }
        }

        if (valid) r = m;
        else l = m+1;
        
    }
    fout << l+1;
    fin.close();
    fout.close();
    return 0;
}