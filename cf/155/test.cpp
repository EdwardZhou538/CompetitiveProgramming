#include <iostream>
#include <string>
#include <fstream>

using namespace std;
long long fastmod(long long a, long long b) {
    return (a >= b) ? a % b : a;
}

long long factorial(long long n) {
    long long total = 1;
    long long divisor = 998244353;
    for (long long i = 1; i <= n; i++) {
        total = fastmod(total * i, divisor);
        cout << i << ": " << total << endl;
    }
    return total;
}


int main() {
    //long long val = factorial(10*10*10*10);
    long long val = factorial(10000);
    /*ofstream fout;
    fout.open("alternate.in");
    for (int i = 0; i < 10*10*10*10; i++) {
        fout << '0';
    }
    fout << '1';
    fout.close();*/
    return 0;
}