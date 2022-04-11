#include <bits/stdc++.h>
using namespace std;

struct segNode {
    int val;
    int l, r;
    segNode *left, *right;
    segNode(int _l, int _r) : val(0), l(_l), r(_r), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    segNode* root = nullptr;

public:
    segNode* build(int l, int r) {
        auto root = new segNode(l, r);
        if(l == r) return root;
        int mid = l + ((r - l) >> 1);
        root->left = build(l, mid);
        root->right = build(mid + 1, r);
        return root;
    }
    void insert(segNode* root, int index) {
        ++root->val;
        if(root->l == root->r) return;
        int mid = root->l + ((root->r - root->l) >> 1);
        if(index <= mid) {
            insert(root->left, index);
        } else {
            insert(root->right, index);
        }
    }
    int count(segNode* root, int a1, int a2) {
        if(a1 > root->r || a2 < root->l) return 0;
        if(a1 <= root->l && a2 >= root->r) return root->val;
        return count(root->left, a1, a2) + count(root->right, a1, a2);
    }
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
        root = build(0, mp.size() - 1);
        int ans = 0;
        for(auto num : preSum) {
            int left = mp[num - upper];
            int right = mp[num - lower];
            ans += count(root, left, right);
            insert(root, mp[num]);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}