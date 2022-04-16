#include <bits/stdc++.h>
using namespace std;

//对任意位置有preSum = total - preSum - nums[i] -> 2 * preSum = total
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int preSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(2 * preSum + nums[i] == total) return i;
            preSum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}