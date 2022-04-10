#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int m, int n, int x, int k) {
        int count = 0;
        for(int i = 1; i <= m; ++i) {
            count += min(int(x / i), n);
        }
        return count >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m * n, ans = 0;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(check(m, n, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}