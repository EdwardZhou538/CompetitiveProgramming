#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    
    fin.open("speeding.in");
    int n;
    int m;
    fin >> n >> m;

    int road[n][2];
    int bessie[m][2];
    road[0][0] = 0;
    bessie[0][0] = 0;
    fout.open("speeding.out");

    for (int i = 0; i < n; i++) {
        int road_length;
        fin >> road_length >> road[i][1];
        if (i == n-1) continue;
        else road[i+1][0] = road[i][0] + road_length;
    }
    /*for (int i = 0; i < n; i++) {
        cout << i << ": " << road[i][0] << ", " << road[i][1] << endl;
    } */

    for (int i = 0; i < m; i++) {
        int road_length;
        fin >> road_length >> bessie[i][1];
        if (i == n-1) continue;
        else bessie[i+1][0] = bessie[i][0] + road_length;
    }

    /*for (int j = 0; j < m; j++) {
        cout << j << ": " << bessie[j][0] << ", " << bessie[j][1] << endl;
    }*/
    int max_speed = 0;
    int curr_segment = 0;
    int bessie_road = 0;
    while (bessie_road < m) {
        //cout << "Bessie segment and speed: " << bessie[bessie_road][0] << ", " << bessie[bessie_road][1] << endl;
        //cout << "Current segment and speed limit: " << road[curr_segment][0] << ", " << road[curr_segment][1] << endl;
        max_speed = max(max_speed, bessie[bessie_road][1] - road[curr_segment][1]);
        if(bessie_road == m-1 && curr_segment != n-1) {
            curr_segment++;
        }
        else if (bessie_road != m-1 && curr_segment == n-1) {
            bessie_road++;
        }
        else if (bessie_road == m-1 && curr_segment == n-1) {
            bessie_road++;
        }
        else if (bessie[bessie_road + 1][0] < road[curr_segment + 1][0]) {
            bessie_road++;
        }
        else if (bessie[bessie_road + 1][0] > road[curr_segment+1][0]) {
            curr_segment++;
        }
        else {
            bessie_road++;
            curr_segment++;
        }
    }
    
    fout << max_speed;
    fin.close();
    fout.close();
}