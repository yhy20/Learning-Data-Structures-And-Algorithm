#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        long long ans = 0;
        vector<int> diff(n);
        for(int i = 0; i < n; ++i)
            diff[i] = nums1[i] - nums2[i];
        sort(diff.begin(), diff.end());
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < r && diff[l] + diff[r] <= 0)
                ++l;
            if(l == r) break;
            ans += r - l;
            --r;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}