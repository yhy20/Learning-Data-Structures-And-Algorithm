#include <bits/stdc++.h>
using namespace std;

//通过贡献度，计算质因数5的个数
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n) {
            n = int(n / 5);
            ans += n;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}