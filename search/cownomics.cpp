#include <bits/stdc++.h>

using namespace std;
int main() {
    ifstream fin;
    ofstream fout;

    fin.open("cownomics.in");
    int n;
    int m;
    fin >> n >> m;

    char spotty_genomes[n][m];
    char plain_genomes[n][m];
    
    for (int i = 0; i < n; i++) {
        string genome;
        fin >> genome;
        for (int j = 0; j < m; j++) {
            spotty_genomes[i][j] = genome.at(j);
        }
    }

    for (int i = 0; i < n; i++) {
        string genome;
        fin >> genome;
        for (int j = 0; j < m; j++) {
            plain_genomes[i][j] = genome.at(j);
        }
    }

    int distinct_traits = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            for (int k = j+1; k < m; k++) {
                bool distinct = true;
                for (int o = 0; o < n; o++) {
                    for (int p = 0; p < n; p++) {
                        if (spotty_genomes[o][i] == plain_genomes[p][i] && spotty_genomes[o][j] == plain_genomes[p][j] && spotty_genomes[o][k] == plain_genomes[p][k]) {
                            distinct = false;
                            break;
                        }
                    }
                    if (!distinct) break;
                }
                if (distinct) distinct_traits++;
            }
        }
    }

    fout.open("cownomics.out");
    fout << distinct_traits;
    fin.close();
    fout.close();
    return 0;

}