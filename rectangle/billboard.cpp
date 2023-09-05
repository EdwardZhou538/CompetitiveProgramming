#include <bits/stdc++.h>

using namespace std;
struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

//amt of area visible from r1
int overlap_area(rectangle r1, rectangle r2) {
    int x_overlap = max(0, min(r1.x2, r2.x2) - max(r1.x1, r2.x1));
    int y_overlap = max(0, min(r1.y2, r2.y2) - max(r1.y1, r2.y1));
    return x_overlap * y_overlap;
}

int main() {
    ifstream fin;
    ofstream fout;

    rectangle r1;
    rectangle r2;
    rectangle r3;

    fin.open("billboard.in");

    fin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    fin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    fin >> r3.x1 >> r3.y1 >> r3.x2 >> r3.y2;

    int total_area = 0;
    total_area += (r1.x2 - r1.x1) * (r1.y2 - r1.y1) - overlap_area(r1, r3);
    total_area += (r2.x2 - r2.x1) * (r2.y2 - r2.y1) - overlap_area(r2, r3);
    fout.open("billboard.out");
    fout << total_area;

    fin.close();
    fout.close();
    return 0;
}