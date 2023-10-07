#include <random>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open("concat.in");
    int n = 50000;
    fout << n << endl;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(97,122);

    for (int i = 0; i < n; i++) {
        fout << char(dist(rng)) << endl;
    }

    fout.close();
    return 0;
}