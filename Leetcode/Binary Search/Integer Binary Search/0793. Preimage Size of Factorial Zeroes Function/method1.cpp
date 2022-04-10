#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check(long long n, int k) {
        int ret = 0;
        while(n) {
            n = n / 5;
            ret += n;
        }
        return ret;
    }
    int preimageSizeFZF(int k) {
        long long l = 0, r = 4000100000;
        while(l <= r) {
            long long mid = l + ((r - l) >> 1);
            int t = check(mid, k);
            if(t == k)
                return 5;
            else if(t > k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return 0;
    }
};

int main() {
    Solution s;

    return 0;
}