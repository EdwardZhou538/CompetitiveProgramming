#include <bits/stdc++.h>

using namespace std;

bool sortcol(vector<long long>& v1, vector<long long>& v2) {
    return v1[0] < v2[0];
}

int main () {
    ifstream fin;
    ofstream fout;

    fin.open("cowqueue.in");
    fout.open("cowqueue.out");

    int n;
    fin >> n;

    vector<vector<long long>> times;

    for (int i = 0; i < n; i++) {
        long long a, b;
        fin >> a >> b;
        times.push_back({a,b});
    }
    
    sort(times.begin(), times.end(), sortcol);

    //for (int i = 0; i < n; i++) cout << times[i][0] << " " << times[i][1] << endl;

    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < times[i][0]) current_time = times[i][0] + times[i][1];
        else current_time += times[i][1];
        //cout << current_time << endl;
    }

    fout << current_time;
    fin.close();
    fout.close();
    return 0;
}