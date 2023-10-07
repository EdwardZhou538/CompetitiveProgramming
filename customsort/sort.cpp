#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    fin.open("sort.in");
    fout.open("sort.out");

    int n;
    fin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }

    bool sorted = false;
    int num_moos = 0;

    while (!sorted) {
        sorted = true;
        num_moos++;

        for (int i = 0; i < n-1; i++) {
            if (arr[i+1] < arr[i]) {
                swap(arr[i], arr[i+1]);
                sorted = false;
            }
        }
    }
    fout << num_moos;
    fin.close();
    fout.close();

    return 0;
}