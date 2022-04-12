#include <bits/stdc++.h>
using namespace std;

//前缀和 + 离散化 + 数组线段树(AC)
class SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int _n) : n(_n), tree(n * 4) {}
    void insert(int index, int node, int s, int e) {
        ++tree[node];
        if(s == e) {
            return;
        }
        int mid = s + ((e - s) >> 1);
        int l = node * 2 + 1, r = node * 2 + 2;
        if(index <= mid) {
            insert(index, l, s, mid);
        } else {
            insert(index, r, mid + 1, e);
        }
    }
    int count(int left, int right, int node, int s, int e) {
        if(left > e || right < s) return 0;
        if(left <= s && right >= e) return tree[node];
        int mid = s + ((e - s) >> 1);
        int l = node * 2 + 1, r = node * 2 + 2;
        return count(left, right, l, s, mid) + count(left, right, r, mid + 1, e);
    }
};

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
        SegmentTree tree(idx);
        for(auto num : preSum) {
            int left = mp[num - upper];
            int right = mp[num - lower];
            ans += tree.count(left, right, 0, 0, idx - 1);
            tree.insert(mp[num], 0, 0, idx - 1);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}