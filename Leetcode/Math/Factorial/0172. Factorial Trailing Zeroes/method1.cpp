#include <bits/stdc++.h>
using namespace std;

//枚举n!中每一个数，计数质因数5的个数
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int i = 5; i <= n; i = i + 5) {
            for(int j = i; j % 5 == 0; j /= 5) ++ans;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}