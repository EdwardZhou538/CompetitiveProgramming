#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("lineup.in");
    fout.open("lineup.out");

    int n;
    fin >> n;

    string names[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    vector<int> ordering[8];
    for (int i = 0; i < n; i++) {
        string cow1, cow2, garbage;
        fin >> cow1 >> garbage >> garbage >> garbage >> garbage >> cow2;
        int idx1, idx2;

        for (int i = 0; i < 8; i++) {
            if (names[i] == cow1) idx1 = i;
            if (names[i] == cow2) idx2 = i;
        }

        ordering[idx1].push_back(idx2);
        ordering[idx2].push_back(idx1);
    }

    bool named_cows[8];
    for (int i = 0; i < 8; i++) named_cows[i] = false;

    for (int i = 0; i < 8; i++) {
        if (named_cows[i]) continue;
        if (ordering[i].size() == 2) continue;

        fout << names[i] << endl;
        named_cows[i] = true;
        if (ordering[i].size() == 1) {
            int new_cow = ordering[i][0];
            fout << names[new_cow] << endl;
            named_cows[new_cow] = true;
            while (ordering[new_cow].size() == 2) {
                if (named_cows[ordering[new_cow][0]]) new_cow = ordering[new_cow][1];
                else new_cow = ordering[new_cow][0];
                fout << names[new_cow] << endl;
                named_cows[new_cow] = true;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}