#include <bits/stdc++.h>

using namespace std;
int main() {
    //freopen("herdle.in", "r", stdin);

    char word[3][3];

    char guess[3][3];

    for (int i = 0; i < 3; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 3; j++) {
            word[i][j] = row.at(j);
        }
    }

    for (int i = 0; i < 3; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 3; j++) {
            guess[i][j] = row.at(j);
        }
    }

    int num_green = 0;
    int num_yellow = 0;

    int word_count[26];
    int guess_count[26];

    for (int i = 0; i < 26; i++) {
        word_count[i] = 0;
        guess_count[i] = 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (word[i][j] == guess[i][j]) num_green++;

            word_count[int(word[i][j]) - 65]++;
            guess_count[int(guess[i][j]) - 65]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        num_yellow += min(word_count[i], guess_count[i]);
    }

    num_yellow -= num_green;
    cout << num_green << endl;
    cout << num_yellow;
    return 0;
}