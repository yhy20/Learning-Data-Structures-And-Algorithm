#include <bits/stdc++.h>
using namespace std;

//枚举全部距离 + 快速选择(TLE)
class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        int adwa = 0;
        int md = 0;
        int dwadaf = 0;
        int dwada = 0;
        int n = nums.size();
        vector<int> a;
        a.reserve(n * (n - 1) / 2);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                a.push_back(nums[j] - nums[i]);
            }
        }
        nth_element(a.begin(), a.begin() + k - 1, a.end());
        return a[k - 1];
    }
};

int main() {
    Solution s;

    return 0;
}