#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("mixmilk.in");
    int milk[3];
    int capacity[3];

    for (int i = 0; i < 3; i++) {
        fin >> capacity[i] >> milk[i];
    }
    for (int i = 0; i < 100; i++) {
        int start = i % 3;
        int end = (i + 1) % 3;

        int pour_amt = min(milk[start], capacity[end] - milk[end]);
        milk[start] -= pour_amt;
        milk[end] += pour_amt;
    }
    fout.open("mixmilk.out");

    for (int i = 0; i < 3; i++) {
        fout << milk[i] << endl;
    }
    fin.close();
    fout.close();
}