#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("zodiac.in", "r", stdin);

    map<string, int> zodiac;
    zodiac["Ox"] = 0;
    zodiac["Tiger"] = 1;
    zodiac["Rabbit"] = 2;
    zodiac["Dragon"] = 3;
    zodiac["Snake"] = 4;
    zodiac["Horse"] = 5;
    zodiac["Goat"] = 6;
    zodiac["Monkey"] = 7;
    zodiac["Rooster"] = 8;
    zodiac["Dog"] = 9;
    zodiac["Pig"] = 10;
    zodiac["Rat"] = 11;


    map<string, int> years;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string statement;
        getline(cin, statement);
        cout << statement << endl;
    }

    return 0;
}