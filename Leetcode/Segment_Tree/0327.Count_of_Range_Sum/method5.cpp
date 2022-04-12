#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int ret = 0;
        while(x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x, int d) {
        while(x <= n) {
            tree[x] += d;
            x += lowbit(x);
        }
    }
};

//前缀和 + 离散化 + 树状数组(AC)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum;
        preSum.reserve(nums.size() + 1);
        preSum.emplace_back(0);
        for(auto num : nums) {
            sum += num;
            preSum.emplace_back(sum);
        }
        set<long long> numbers;
        for(auto num : preSum) {
            numbers.insert(num - upper);
            numbers.insert(num);
            numbers.insert(num - lower);
        }
        unordered_map<long long, int> mp;
        int idx = 0;
        for(auto num : numbers) {
            mp[num] = idx++;
        }
        int ans = 0;
        BIT bit(idx);
        for(auto num : preSum) {
            int left = mp[num - upper];
            int right = mp[num - lower];
            ans += bit.query(right + 1) - bit.query(left);
            bit.update(mp[num] + 1, 1);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}