#include <bits/stdc++.h>

using namespace std;

struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

bool is_covered(rectangle r1, rectangle r2) {
    return (r1.x1 >= r2.x1 && r1.x2 <= r2.x2 && r1.y1 >= r2.y1 && r1.y2 <= r2.y2);
}

int x_side_covered(rectangle r1, rectangle r2) {
    
}


int main() {
    rectangle w;
    rectangle b1;
    rectangle b2;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    bool covered = false;
    if (is_covered(w, b1) || is_covered(w, b2)) covered = true;


}