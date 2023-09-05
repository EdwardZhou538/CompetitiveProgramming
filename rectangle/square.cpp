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
    fin.open("square.in");

    fin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    fin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
    int x_span = max(r1.x2, r2.x2) - min(r1.x1, r2.x1);
    int y_span = max(r1.y2, r2.y2) - min(r1.y1, r2.y1);
    fout.open("square.out");
    fout << max(x_span, y_span) * max(x_span, y_span);
    fin.close();
    fout.close();
    return 0;
}