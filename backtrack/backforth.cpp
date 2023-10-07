#include <bits/stdc++.h>
using namespace std;

void get_readings(vector<pair<int, int>>& buckets, int day, set<int>& readings, int capacity1, int capacity2) {
    //cout << "day: " << day <<", capacity: " << capacity1 << endl;

    if (day > 4) {
        readings.insert(capacity1);
        return;
    }

    if (day % 2 == 1) {
        for (int i = 0; i < 20; i++) {
            if (buckets[i].second == 1) {
                int amt_drained = min(capacity1, buckets[i].first);
                buckets[i].second = 2;
                get_readings(buckets, day+1, readings, capacity1 - amt_drained, capacity2 + amt_drained);
                buckets[i].second = 1;
            }
        }
    }
    else {
        for (int i = 0; i < 20; i++) {
            if (buckets[i].second == 2) {
                int amt_drained = min(capacity2, buckets[i].first);
                buckets[i].second = 1;
                get_readings(buckets, day+1, readings, capacity1 + amt_drained, capacity2 - amt_drained);
                buckets[i].second = 2;
            }
        }
    }
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("backforth.in");
    fout.open("backforth.out");

    vector<pair<int, int>> buckets;

    for (int i = 0; i < 10; i++) {
        int bucket;
        fin >> bucket;
        buckets.push_back({bucket, 1});
    }

    for (int i = 0; i < 10; i++) {
        int bucket;
        fin >> bucket;
        buckets.push_back({bucket, 2});
    }

    /*for (int i = 0; i < 20; i++) {
        cout << buckets[i].first << " " << buckets[i].second << endl;
    }*/
    set<int> readings;
    get_readings(buckets, 1, readings, 1000, 1000);
    //for (int element: readings) cout << element << " ";
    //cout << endl;
    fout << readings.size();

    fin.close();
    fout.close();
    return 0;

}