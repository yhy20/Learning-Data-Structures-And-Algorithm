#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    int m = int(sqrt(n));
    for (int i = 2; i <= m; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}