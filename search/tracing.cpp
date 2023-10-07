#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}


int main() {
    ifstream fin;
    ofstream fout;

    fin.open("tracing.in");
    fout.open("tracing.out");

    int n, t;
    fin >> n >> t;

    string state;
    fin >> state;

    set<int> end_state;
    for (int i = 0; i < n; i++) {
        if (state[i] == 1) end_state.insert(i);
    }

    vector<vector<int>> handshakes;

    for (int i = 0; i < t; i++) {
        vector<int> something;
        for (int j = 0; j < 3; j++) {
            int k;
            fin >> k;
            something.push_back(k-1);
        }
        handshakes.push_back(something);
    }

    sort(handshakes.begin(), handshakes.end(), cmp);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++) {
            cout << handshakes[i][j] << " ";
        }
        cout << endl;
    }

    int min_handshakes = INT_MAX;
    int max_handshakes = -1;

    for (int i = 0; i < n; i++) {
        if (state[i] == 0) continue;
        vector<int> diseased = {i};
        int curr_min = INT_MAX;
        int curr_max = -1;
        int current_cow = 0;
        while (current_cow < diseased.size()) {
            for (int j = 0; j < t; j++) {
                int num_handshakes = 0;
                if (handshakes[j][0] == diseased[current_cow]) {
                    if !(end_state.count(handshakes[j][1])) {
                        curr
                    }
                }
            }
        }
        for (int j = 0; j < t; j++) {
        }
    }

    return 0;
}