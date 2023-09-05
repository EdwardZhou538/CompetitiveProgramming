#include <bits/stdc++.h>

using namespace std;

int main() {
    char board[3][3];

    ifstream fin;
    ofstream fout;

    fin.open("tttt.in");
    fout.open("tttt.out");

    for (int i = 0; i < 3; i++) {
        string row;
        fin >> row;

        for (int j = 0; j < 3; j++) {
            board[i][j] = row.at(j);
        }
    }

    set<char> single_char;
    set<set<char>> char_pair;

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1]) {
            if (board[i][1] == board[i][2]) single_char.insert(board[i][0]);
            else char_pair.insert({board[i][1], board[i][2]});
        } else if (board[i][0] == board[i][2]) {
            char_pair.insert({board[i][0], board[i][1]});
        } else if (board[i][1] == board[i][2]) {
            char_pair.insert({board[i][0], board[i][1]});
        }
        
        if (board[0][i] == board[1][i]) {
            if (board[1][i] == board[2][i]) single_char.insert(board[0][i]);
            else char_pair.insert({board[1][i], board[2][i]});
        } else if (board[1][i] == board[2][i]) {
            char_pair.insert({board[0][i], board[2][i]});
        } else if (board[0][i] == board[2][i]) {
            char_pair.insert({board[0][i], board[1][i]});
        }
    }
    if (board[0][0] == board[1][1]) {
        if (board[1][1] == board[2][2]) single_char.insert(board[0][0]);
        else char_pair.insert({board[1][1], board[2][2]});
    } else if (board[0][0] == board[2][2]) {
        char_pair.insert({board[0][0], board[1][1]});
    } else if (board[1][1] == board[2][2]) {
        char_pair.insert({board[0][0], board[2][2]});
    }
    if (board[2][0] == board[1][1]) {
        if (board[1][1] == board[0][2]) single_char.insert(board[0][2]);
        else char_pair.insert({board[2][0], board[0][2]});
    } else if (board[2][0] == board[0][2]) {
        char_pair.insert({board[0][2], board[1][1]});
    } else if (board[1][1] == board[0][2]) {
        char_pair.insert({board[0][2], board[2][0]});
    }

    /*for (set<char> element: char_pair) {
        for (char e: element) {
            cout << e << " ";
        }
        cout << endl;
    }*/

    fout << single_char.size() << endl;
    fout << char_pair.size() << endl;
    fin.close();
    fout.close();
}