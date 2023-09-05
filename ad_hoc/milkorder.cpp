#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("milkorder.in");
    fout.open("milkorder.out");

    int n, m, k;
    fin >> n >> m >> k;

    int order[n];
    for (int i = 0; i < n; i++) order[i] = 0;

    int desired_order[m];
    bool m_contains_1 = false;
    bool k_contains_1 = false;
    int one_pos = -1;
    for (int i = 0; i < m; i++) {
        fin >> desired_order[i];
        if (desired_order[i] == 1) {
            m_contains_1 = true;
            one_pos = i;
        }
    }
    for (int i = 0; i < k; i++) {
        int cow, place;
        fin >> cow >> place;
        order[place-1] = cow;
        if (cow == 1) {
            fout << place;
            k_contains_1 = true;
        }
    }

    if (!k_contains_1 && m_contains_1) {
        int nearest_idx = -1;
        int nearest_desired_idx = -1;
        for (int i = 0; i < n; i++) {
            if (order[i] != 0) {
                for (int j = 0 ; j < one_pos; j++ ) {
                    if (order[i] == desired_order[j]) {
                        nearest_idx = i;
                        nearest_desired_idx = j;
                    }
                }
            }
        }
        if (nearest_idx == -1) {
            int start = 0;
            while(order[start] != 0) start++;
            for (int i = 0; i < one_pos; i++) {
                start++;
                while(order[start] != 0) start++;
            }
            fout << start + 1;
        }
        else {
            int start = nearest_idx;
            for (int i = nearest_desired_idx; i < one_pos; i++) {
                start++;
                while(order[start] != 0) start++;
            }
            fout << start + 1 ;
        }
    }
    else if (!k_contains_1 && !m_contains_1) {
        bool get_the_fuck_out = false;


        for (int i = 0; i < n; i++) {
            if (order[i] != 0) {
                for (int j = 0; j < m; j++) {
                    if (order[i] == desired_order[j]) {
                        get_the_fuck_out = true;
                        int desired_pointer = j - 1;
                        int position_pointer = i - 1;
                        while (desired_pointer >= 0) {
                            while(order[position_pointer] != 0) position_pointer--;
                            order[position_pointer] = desired_order[desired_pointer];
                            desired_pointer--;
                            position_pointer--;
                        }
                        break;
                    }
                }

            }
            if(get_the_fuck_out) break;
        }
        for (int i = 0; i < n; i++) {
            if (order[i] == 0) {
                fout << i + 1;
                break;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
    
}