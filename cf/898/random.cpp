#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout;
    fout.open("abbc.in");
    fout << 1 << endl;
    bool wrote_b = false;
    srand(10);
    for (int i = 0; i < 50; i++) {
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        if (r < 0.7 || wrote_b) {
            fout << "A";
            wrote_b = false;
        }
        else {
            fout << "B";
            wrote_b = true;
        }
    }
    fout.close();
    return 0;
}