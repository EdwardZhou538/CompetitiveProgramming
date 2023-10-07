#include <bits/stdc++.h>

using namespace std;

bool cmp1(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first < b.first;
}

bool cmp2(pair<long long, long long> a, pair<long long, long long> b) {
    return a.second < b.second;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("split.in");
    fout.open("split.out");

    long long n;
    fin >> n;

    pair<long long, long long> points[n];
    for (long long i = 0; i < n; i++) {
        fin >> points[i].first >> points[i].second;
    }

    sort(points, points + n, cmp1);

    long long end_x[n];

    long long min_y = LLONG_MAX;
    long long max_y = 0;

    for (long long i = 0; i < n; i++) {
        max_y = max(max_y, points[i].second);
        min_y = min(min_y, points[i].second);
        end_x[i] = (max_y - min_y) * (points[i].first - points[0].first);
    }
    long long start_x[n];
    min_y = LLONG_MAX;
    max_y = 0;
    for (long long i = n-1; i >= 0; i--) {
        max_y = max(max_y, points[i].second);
        min_y = min(min_y, points[i].second);
        start_x[i] = (max_y - min_y) * (points[n-1].first - points[i].first);
    }

    long long x_div = LLONG_MAX;

    for (long long i = 0; i < n-1; i++) {
        if (points[i].first == points[i+1].first) continue;

        x_div = min(x_div, start_x[i + 1] + end_x[i]);
        //cout << x_div << endl;
    }

    /*for (long long i = 0; i < n; i++) {
        cout << start_x[i] << " ";
    }*/

    //cout << endl;
    sort(points, points + n, cmp2);

    long long end_y[n];

    long long min_x = LLONG_MAX;
    long long max_x = 0;

    for (long long i = 0; i < n; i++) {
        max_x = max(max_x, points[i].first);
        min_x = min(min_x, points[i].first);
        end_y[i] = (max_x - min_x) * (points[i].second - points[0].second);
    }
    long long start_y[n];
    min_x = LLONG_MAX;
    max_x = 0;
    for (long long i = n-1; i >= 0; i--) {
        max_x = max(max_x, points[i].first);
        min_x = min(min_x, points[i].first);
        start_y[i] = (max_x - min_x) * (points[n-1].second - points[i].second);
    }

    long long y_div = LLONG_MAX;

    for (long long i = 0; i < n-1; i++) {
        if (points[i].second == points[i+1].second) continue;

        y_div = min(y_div, start_y[i + 1] + end_y[i]);
        //cout << y_div << endl;
    }

    /*for (long long i = 0; i < n; i++) {
        cout << start_y[i] << " ";
    }
    cout << endl;*/

    fout << start_x[0] - min(x_div, y_div);
    fin.close();
    fout.close();
    return 0;
}