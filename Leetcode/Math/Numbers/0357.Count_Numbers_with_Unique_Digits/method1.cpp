#include <bits/stdc++.h>
using namespace std;

//排列组合公式
class Solution {
public:
    int C(int n, int m) {
        int ret1 = 1, ret2 = 1;
        for(int i = 1; i <= m; ++i) {
            ret1 *= n--;
            ret2 *= i;
        }
        return ret1 / ret2;
    }
    int A(int n) {
        int ret = 1;
        for(int i = 1; i <= n; ++i) {
            ret *= i;
        }
        return ret;
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        for(int i = 1; i <= n; ++i) {
            ans += C(10, i) * A(i) - C(9, i - 1) * A(i - 1);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}