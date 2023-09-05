#include <bits/stdc++.h>

using namespace std;

int char_to_int(char c) {
    return int(c) - 97;
}

int main() {
    ifstream fin;
    ofstream fout;

    int letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = 0;
    }

    fin.open("blocks.in");
    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        string word1;
        string word2;
        fin >> word1 >> word2;
        int side1_letters[26];
        for (int i = 0; i < 26; i++) side1_letters[i] = 0;

        int side2_letters[26];
        for (int i = 0; i < 26; i++) side2_letters[i] = 0;

        for (int j = 0; j < word1.size(); j++) {
            side1_letters[char_to_int(word1.at(j))]++;
        }

        for (int j = 0; j < word2.size(); j++) {
            side2_letters[char_to_int(word2.at(j))]++;
        }

        for (int j = 0; j < 26; j++) {
            letters[j] += max(side1_letters[j], side2_letters[j]);
        }

    }

    fout.open("blocks.out");
    for (int i = 0; i < 26; i++) {
        fout << letters[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}