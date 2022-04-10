#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int> &a, int d, int k) {
        int count = 0;
        for (auto num : a) {
            count += int(num / d);
            if (count >= k) return true;
        }
        return false;
    }
    int maxLength(vector<int> &ribbons, int k) {
        int l = 1, r = *max_element(ribbons.begin(), ribbons.end());
        int ans = 0;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(ribbons, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}