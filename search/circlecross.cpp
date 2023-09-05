#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("circlecross.in");
    fout.open("circlecross.out");

    string layout;
    fin >> layout;

    int positions[26][2];
    for(int i = 0; i < 26; i++) {
        positions[i][0] = -1;
    }

    for (int i =0 ; i < 52; i++) {
        int letter = layout.at(i) - 65;
        if (positions[letter][0] == -1) positions[letter][0] = i;
        else positions[letter][1] = i;
    }

    for (int i = 0 ; i < 26; i++) {
        if (positions[i][1] - positions[i][0] > 25) {
            positions[i][1] -= 52;
            swap(positions[i][0], positions[i][1]);
        }
        cout << positions[i][0] << " " << positions[i][1] << endl;
    }

    int num_crossings = 0;


    for (int i = 0; i < 26; i++) {
        for (int j = i+1; j < 26; j++) {
            if (positions[j][1] > positions[i][1] && positions[j][0] > positions[i][0] && positions[j][0] < positions[i][1]) num_crossings++;
            else if (positions[i][1] > positions[j][1] && positions[i][0] > positions[j][0] && positions[i][0] < positions[j][1]) num_crossings++;
            else if (positions[i][1] - 52 > positions[j][1] && positions[i][0] - 52 > positions[j][0] && positions[i][0] - 52 < positions[j][1]) num_crossings++;
            else if (positions[i][1] - 52 < positions[j][1] && positions[i][0] - 52 < positions[j][0] && positions[j][0] < positions[i][1] - 52) num_crossings++;
            else if (positions[i][1] > positions[j][1] - 52 && positions[i][0] > positions[j][0] - 52 && positions[i][0] < positions[j][1] - 52) num_crossings++;
            else if (positions[i][1] < positions[j][1] - 52 && positions[i][0] < positions[j][0] - 52 && positions[j][1] - 52 < positions[i][0]) num_crossings++;
        }
    }

    fout << num_crossings;
    fin.close();
    fout.close();
}