#include <bits/stdc++.h>
using namespace std;

int main () {
    ifstream fin;
    ofstream fout;

    fin.open("notlast.in");
    fout.open("notlast.out");

    map<string, int> prod;

    prod["Bessie"] = 0;
    prod["Elsie"] = 0;
    prod["Daisy"] = 0;
    prod["Gertie"] = 0;
    prod["Annabelle"] = 0;
    prod["Maggie"] = 0;
    prod["Henrietta"] = 0;

    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int amt;
        fin >> name >> amt;

        prod[name] += amt;
    }

    int least

    for (auto &name: prod) {

    }
}