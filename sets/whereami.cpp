#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    fin.open("whereami.in");
    fout.open("whereami.out");

    int n;

    fin >> n;


    string house_colors;
    fin >> house_colors;

    for (int i = 1; i <= n; i++) {
        set<string> distinct_colors;

        for (int j = 0; j <= n - i; j++) {
            distinct_colors.insert(house_colors.substr(j, i));
        }
        if (distinct_colors.size() == n-i+1) {
            fout << i;
            break;
        }
        /*cout << i << endl;
        for (string element : distinct_colors) { cout << element << endl; }*/
    }

    fin.close();
    fout.close();
    return 0;
}