#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("abc.in", "r", stdin);

    int nums[7];

    int top = 0;

    for (int i = 0; i < 7; i++) {
        cin >> nums[i];
        top = max(nums[i], top);
    }
    int bot = INT_MAX;
    int bot_idx = -1;
    int bot_2 = INT_MAX;

    for (int i = 0; i < 7; i++) {
        if (bot >= nums[i]) {
            bot = nums[i];
            bot_idx = i;
        }
    }

    for (int i = 0; i < 7; i++) {
        if (i == bot_idx) continue;

        if (bot_2 >= nums[i]) bot_2 = nums[i];
    }

    int num_3 = top - bot - bot_2;

    cout << bot << " " << bot_2 << " " << num_3 << endl;
}