#include <bits/stdc++.h>

using namespace std;

int partition(vector<vector<int>>& cows, int start, int end, int coord)
{
 
    int pivot = cows[start][coord];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (cows[i][coord] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(cows[pivotIndex], cows[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (cows[i][coord] <= pivot) {
            i++;
        }
 
        while (cows[j][coord] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(cows[i++], cows[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(vector<vector<int>>& cows, int start, int end, int coord)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the cowsay
    int p = partition(cows, start, end, coord);
 
    // Sorting the left part
    quickSort(cows, start, p - 1, coord);
 
    // Sorting the right part
    quickSort(cows, p + 1, end, coord);
}

int main() {
    freopen("rut.in", "r", stdin);

    int n;
    cin >> n;
    vector<vector<int>> east_cows;
    vector<vector<int>> north_cows;
    
    for (int i = 0 ; i < n; i++) {
        char direction;
        int x;
        int y;
        cin >> direction >> x >> y;
        if (direction == 'N') {
            north_cows.push_back({x, y, 0, i, 0});
        }
        else {
            east_cows.push_back({x, y, 0, i, 0});
        }
    }

    quickSort(north_cows, 0, north_cows.size() - 1, 0);
    quickSort(east_cows, 0, east_cows.size() - 1, 1);


    /*for (int i = 0; i < east_cows.size(); i++) {
        cout << "(" << east_cows[i][0] << ", " << east_cows[i][1] << ")" << " ";
    }
    cout << endl;
    for (int i = 0; i < north_cows.size(); i++) {
        cout << "(" << north_cows[i][0] << ", " << north_cows[i][1] << ")" << " ";
    }*/

    for (int i = 0; i < east_cows.size(); i++) {
        for (int j = 0; j < north_cows.size(); j++) {
            if (east_cows[i][2] != 0 && east_cows[i][2]  < north_cows[j][0]) continue;
            if (north_cows[j][2] != 0 && north_cows[j][2]  < east_cows[i][1]) continue;

            if (east_cows[i][0] <= north_cows[j][0] && east_cows[i][1] >= north_cows[j][1]) {
                //cout << i << " " << j << endl;
                if (east_cows[i][1] - north_cows[j][1] > north_cows[j][0] - east_cows[i][0]) {
                    north_cows[j][2] = east_cows[i][1];
                    north_cows[j][4]++;
                }
                else if (east_cows[i][1] - north_cows[j][1] < north_cows[j][0] - east_cows[i][0]) {
                    east_cows[i][2] = north_cows[j][0];
                    east_cows[i][4]++;
                }
            }
        }
    }
    quickSort(north_cows, 0, north_cows.size() - 1, 3);
    quickSort(east_cows, 0, east_cows.size() - 1, 3);
    /*for (int i = 0; i < east_cows.size(); i++) {
        cout << east_cows[i][3] << ":(" << east_cows[i][0] << ", " << east_cows[i][1] << ")" << " ";
    }
    cout << endl;
    for (int i = 0; i < north_cows.size(); i++) {
        cout << north_cows[i][3] << ":(" << north_cows[i][0] << ", " << north_cows[i][1] << ")" << " ";
    }*/

    int east_ptr = 0;
    int north_ptr = 0;

    for (int i = 0; i < n; i++) {
        if (east_ptr < east_cows.size() && east_cows[east_ptr][3] == i) {
            cout << east_cows[east_ptr][4] << endl;
            east_ptr++;
        }
        else if (north_ptr < north_cows.size() && north_cows[north_ptr][3] == i) {
            cout << north_cows[north_ptr][4] << endl;
            north_ptr++;
        }
    }

}