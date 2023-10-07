#include <bits/stdc++.h>

using namespace std;
struct cow {
    int seniority; 
    int time;
    int duration;
};

bool cmp1 (cow a, cow b) {
    return a.time < b.time;
}

bool cmp2 (cow a, cow b) {
    return a.seniority < b.seniority;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("convention2.in");
    fout.open("convention2.out");
    int n; fin >> n;
    cow arrivals[n];
    for (int i = 0; i < n; i++) {
        fin >> arrivals[i].time >> arrivals[i].duration;
        arrivals[i].seniority = -i;
    }
    sort(arrivals, arrivals + n, cmp1);
    priority_queue<cow, vector<cow>, decltype(&cmp2)> pq(cmp2);
    int idx = 1;
    int end_time = arrivals[0].time + arrivals[0].duration;
    int max_time = 0;
    for (int i = 0; i < n; i++) {
        //cout << arrivals[i].time << " " << arrivals[i].duration << " " << arrivals[i].seniority << endl;
    }
    //cout << endl;

    while (idx < n) {
        while (arrivals[idx].time < end_time) {
            pq.push(arrivals[idx]);
            idx++;
            if (idx == n) break;
        }
        while (!pq.empty()) {
            cow next_cow = pq.top();
            //cout << next_cow.seniority << " " << next_cow.time << " " << next_cow.duration << endl;
            max_time = max(max_time, end_time - next_cow.time);
            end_time += next_cow.duration;
            pq.pop();
            while (idx < n && arrivals[idx].time < end_time) {
                pq.push(arrivals[idx]);
                idx++;
            }
        }
        //cout << endl;
        if (idx < n && arrivals[idx].time >= end_time) {
            end_time = arrivals[idx].time + arrivals[idx].duration;
            idx++;
        }

    }
    fout << max_time;
    fin.close();
    fout.close();
    return 0;
}