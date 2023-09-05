#include <bits/stdc++.h>

using namespace std;

struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

int main() {
    ifstream fin;
    ofstream fout;

    rectangle r1;
    rectangle r2;
    rectangle r3;

    fin.open("billboard.in");
    fout.open("billboard.out");

    fin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    fin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

    int x_overlap = max(0, min(r1.x2, r2.x2) - max(r1.x1, r2.x1));
    int y_overlap = max(0, min(r1.y2, r2.y2) - max(r1.y1, r2.y1));

    if (x_overlap == r1.x2 - r1.x1) {
        if (y_overlap == r1.y2 - r1.y1) {
            fout << 0;
        }
        else {
            fout << (r1.x2 - r1.x1) * (r1.y2 - r1.y1 - y_overlap);
        }
    }
    else if (y_overlap == r1.y2 - r1.y1) {
        fout << (r1.x2 - r1.x1 - x_overlap) * (r1.y2 - r1.y1);
    }
    else {
        fout << (r1.x2 - r1.x1) * (r1.y2 - r1.y1);
    }
    fin.close();
    fout.close();
    return 0;

}