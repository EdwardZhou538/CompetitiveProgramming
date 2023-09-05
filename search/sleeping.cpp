#include <bits/stdc++.h>

using namespace std;

void num_mods(vector<int> classes) {

    int total = 0;
    for (int i = 0; i < classes.size(); i++) {
        total += classes[i];
    }
      
}

int main() {
    freopen("sleeping.in", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> classes(n);
        for (int i = 0; i < n; i++) {
            cin >> classes[i];
        }
        num_mods(classes);
    }
    
}