#include <bits/stdc++.h>

using namespace std;

void solve() {
    int die1[4];
    int die2[4];

    for (int i = 0; i < 4; i++) {
        cin >> die1[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> die2[i];
    }
    int greater_die;
    int num_wins1 = 0;
    int num_wins2 = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (die1[i] > die2[j]) num_wins1++;
            if (die1[i] < die2[j]) num_wins2++;
        }
    }
    if (num_wins1 == num_wins2) {
        cout << "no" << endl;
        return;
    }
    else if (num_wins1 < num_wins2) {
        greater_die = 2;
    }
    else {
        greater_die = 1;
    }

    

}

int main() {
    freopen("dice.in", "r", stdin);

    int t;
    cin >> t;

    int die1[4];
    int die2[4];
    int die


}