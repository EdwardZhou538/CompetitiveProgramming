#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    int length[t];
    int max_length = 0;
    for (int i = 0; i < t; i++) {
        cin >> length[i];
        max_length = max(max_length, length[i]);
    }
    long long arr[max_length];

    arr[0] = (long long)1;
    arr[1] = (long long)3;
    for (int i = 2; i < max_length; i++) {
        arr[i] = arr[i-1] + 1;
        while (3*arr[i] % (arr[i-1]+arr[i-2]) == 0) arr[i]++;
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < length[i]; j++) cout << arr[j] << " ";
        cout << endl;
    }
    return 0;
}