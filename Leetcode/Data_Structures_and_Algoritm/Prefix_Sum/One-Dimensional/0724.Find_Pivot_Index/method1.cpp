#include <bits/stdc++.h>
using namespace std;

//求前缀和直接进行判断即可，注意边界条件
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        partial_sum(nums.begin(), nums.end(), nums.begin());
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                if(nums[n - 1] - nums[0] == 0) return 0;
            } else if(i == n - 1) {
                if(nums[n - 2] == 0) return n - 1;
            } else {
                if(nums[i - 1] == nums[n - 1] - nums[i]) return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}