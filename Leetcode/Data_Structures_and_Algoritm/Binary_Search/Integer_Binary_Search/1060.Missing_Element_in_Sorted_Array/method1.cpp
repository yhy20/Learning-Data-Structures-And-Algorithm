#include <bits/stdc++.h>
using namespace std;

//本题比较有意思，注意先在纸上推导数学公式再写
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int t = nums[mid] - nums[0] - mid;
            if(t >= k) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans == -1 ? (k + nums[0] + n - 1) : (k + nums[0] + ans - 1);
    }
};

int main() {
    Solution s;

    return 0;
}