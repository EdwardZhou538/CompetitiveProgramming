#include <bits/stdc++.h>

using namespace std;

/*int simulate(int barrels[], int pos) {

    int count = 1;
    int l = pos - 1;
    int r = pos + 1;
    int l_radius = 1;
    int r_radius = 1;
    while(l >= 0 && barrels[l+1] - barrels[l] <= l_radius) {
        count++;
        l_radius++;
    }

    while (r < sizeof(barrels)/sizeof(barrels[0]) && barrels[r] - barrels[r-1] >= r_radius) {
        count++;
        r_radius++;
    }
    return count;
}*/

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("angry.in");
    fout.open("angry.out");

    int n;
    fin >> n;

    int barrels[n];
    for (int i = 0; i < n; i++) {
        fin >> barrels[i];
    }

    sort(barrels, barrels + n);
    int num_exploded = 0;

    /*for (int i = 0; i < n; i++) cout << barrels[i] << " ";
    cout << endl;*/

    for (int i = 0; i < n; i++) {
        int count = 1;
        int l_start = i;
        int l_end = i-1;
        int r_start = i;
        int r_end = i+1;
        int l_radius = 1;
        int r_radius = 1;
        //cout << "Iteration: " << i << endl;
        while(l_start >= 0) {
            while (l_end >= 0 && barrels[l_start] - barrels[l_end] <= l_radius) {
                l_end--;
                count++;
            }
            if (l_start == l_end + 1) break;
            l_start = l_end + 1;
            l_radius++;
        }

        while(r_start < n) {
            while (r_end < n && barrels[r_end] - barrels[r_start] <= r_radius) {
                r_end++;
                count++;
            }
            if (r_start == r_end - 1) break;
            r_start = r_end - 1;
            r_radius++;
        }
        num_exploded = max(num_exploded, count);
    }

    fout << num_exploded;
    fin.close();
    fout.close();
    return 0;
}