#include <bits/stdc++.h>

using namespace std;
int main() {
    int pos[3];
    ifstream fin;
    ofstream fout;
    fin.open("herding.in");
    fout.open("herding.out");

    fin >> pos[0] >> pos[1] >> pos[2];

    int min_dist = min(pos[2] - pos[1], pos[1]- pos[0]);
    int max_dist = max(pos[2] -pos[1], pos[1] - pos[0]);

    if (min_dist == 1 && max_dist == 1) {
        fout << 0 << endl;
        fout << 0;
    }
    else if (min_dist == 2) {
        fout << 1 << endl;
        fout << max_dist - 1;
    }
    else if (min_dist == 1) {
        fout << 2 << endl;
        fout << max_dist - 1;
    }
    else {
        fout << 2 << endl;
        fout << max_dist - 1;
    }
    fin.close();
    fout.close();
    return 0;
}