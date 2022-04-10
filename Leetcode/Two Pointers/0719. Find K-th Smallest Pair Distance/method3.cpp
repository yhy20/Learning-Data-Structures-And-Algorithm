#include <bits/stdc++.h>
using namespace std;

//二分查找 + 双指针
//双指针查找距离小于d的pair的个数
class Solution {
public:
    bool check(vector<int> &a, int k, int d) {
        int l = 0, r = 1, count = 0;
        while(r < a.size()) {
            while(l < r && a[r] - a[l] > d) ++l;
            if(a[r] - a[l] <= d) count += r - l;
            r++;
        }
        return count >= k;
    }
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front(), ans = 0;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(check(nums, k, mid)) {
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