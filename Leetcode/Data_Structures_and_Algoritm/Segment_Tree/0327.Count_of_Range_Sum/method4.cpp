#include <bits/stdc++.h>
using namespace std;

struct segNode {
    int val;
    long long l, r;
    segNode *left, *right;
    segNode(long long _l, long long _r) : val(0), l(_l), r(_r), left(nullptr), right(nullptr) {}
};

//前缀和 + 动态增加节点线段树(不需要离散化，TLE)
class Solution {
private:
    segNode* root = nullptr;

public:
    void insert(segNode* root, long long index) {
        ++root->val;
        if(root->l == root->r) return;
        int mid = root->l + ((root->r - root->l) >> 1);
        if(index <= mid) {
            if(!root->left) {
                root->left = new segNode(root->l, mid);
            }
            insert(root->left, index);
        } else {
            if(!root->right) {
                root->right = new segNode(mid + 1, root->r);
            }
            insert(root->right, index);
        }
    }
    int count(segNode* root, long long a1, long long a2) {
        if(!root || a1 > root->r || a2 < root->l) return 0;
        if(a1 <= root->l && a2 >= root->r) return root->val;
        return count(root->left, a1, a2) + count(root->right, a1, a2);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum = {0};
        preSum.reserve(nums.size() + 1);
        for(auto num : nums) {
            sum += num;
            preSum.emplace_back(sum);
        }
        long long mn = LLONG_MAX, mx = LLONG_MIN;
        for(auto num : preSum) {
            mn = min({mn, num, num - upper, num - lower});
            mx = max({mx, num, num - upper, num - lower});
        }
        root = new segNode(mn, mx);
        int ans = 0;
        for(auto num : preSum) {
            ans += count(root, num - upper, num - lower);
            insert(root, num);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}