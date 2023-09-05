#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    //freopen("tracing.in", "r", stdin);
    //freopen("tracing.out", "w", stdout);
    int t;
    cin >> t;
    vector<int> totals;
    for (int i=0; i<t; i++){
        long long n, m;
        cin >> n >> m;
        vector<vector<long long>> game(n, vector<long long>(m));
        for(int j=0; j<n; j++){
            for (int k=0; k<m; k++){
                cin >> game[j][k];
            }
        }
        long long total = 0;
        for (int j=0; j<m; j++){
            vector<long long> coloumn;
            for(int k=0;k<n; k++){
                coloumn.push_back(game[k][j]);
            }
            sort(coloumn.begin(), coloumn.end());
            for (int k=0; k<n; k++){
                total += coloumn[k] * (k);
                total -= coloumn[k] * (n-k-1);
            }
        }

        cout << total << endl;
    }
}
