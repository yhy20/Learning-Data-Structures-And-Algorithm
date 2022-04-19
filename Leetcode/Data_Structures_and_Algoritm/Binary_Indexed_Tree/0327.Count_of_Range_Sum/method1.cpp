#include <bits/stdc++.h>
using namespace std;

//枚举全部的区间和，判断是否满足题意，时间复杂度O(n2)(TLE)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), ans = 0;
        vector<long long> preSum(n + 1);
        for(int i = 1; i <= n; ++i) {
            preSum[i] += preSum[i - 1] + nums[i - 1];
            for(int j = 0; j < i; ++j) {
                long long sum = preSum[i] - preSum[j];
                if(sum >= lower && sum <= upper) ++ans;
            }
        }
        return ans;
    }
};

//对[lower, upper]区间进行枚举，期望upper - lower小时获得较好性能，最坏时间复杂度O(n2)(TLE)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        unordered_map<long long, int> mp;
        int n = nums.size(), ans = 0;
        long long sum = 0;
        mp[0] = 1;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            for(int j = lower; j <= upper; ++j) {
                ans += mp[sum - j];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}