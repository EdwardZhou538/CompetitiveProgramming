#include <bits/stdc++.h>

using namespace std;

int two_block(int a, int b, int operation) {
    if (operation == 0) return a + b;
    if (operation == 1) return a - b;
    if (operation == 2) return a * b;
    if (operation == 3) return a / b;
}

int three_block(int a, int b, int c, int operation1, int operation2) {
    
}

int solve(int nums[]) {
    for (int i = 0 ; i < 4; i++) {
        int total = nums[i];
        
    }
}


int main() {
    freopen("twentyfour.in", "r", stdin);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int nums[4];
        cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    }
}