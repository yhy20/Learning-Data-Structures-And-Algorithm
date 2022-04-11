#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int multiply(int A, int B) {
        int ans = 0;
        for(int i = 31; i >= 0; --i) {
            if((A >> i) & 1) {
                ans += B << i;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}