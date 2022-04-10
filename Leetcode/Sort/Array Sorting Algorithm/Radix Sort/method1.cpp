#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumGap(vector<int>& nums) {
        radixSort(nums);
        return nums;
    }

    void radixSort(vector<int>& nums) {
        if(nums.size() < 2) return;
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> buffer(n);
        int exp = 1;
        while(exp <= maxVal) {
            vector<int> cnt(10);
            for(auto num : nums) {
                int digit = (num / exp) % 10;
                ++cnt[digit];
            }
            for(int i = 1; i < 10; ++i) cnt[i] += cnt[i - 1];
            for(int i = n - 1; i >= 0; --i) {
                int digit = (nums[i] / exp) % 10;
                buffer[cnt[digit] - 1] = nums[i];
                --cnt[digit];
            }
            copy(buffer.begin(), buffer.end(), nums.begin());
            exp *= 10;
        }
    }
};

int main() {
    Solution s;

    return 0;
}