#include <bits/stdc++.h>
using namespace std;

// Segment Tree
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
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;
        a.reserve(n);

        //排序离散化
        for(int i = 0; i < n; ++i) {
            a.emplace_back(nums[i], i);
        }
        sort(a.begin(), a.end(), [](auto& l, auto& r) -> bool {
            return l.first < r.first || (l.first == r.first && l.second < r.second);
        });
        for(int i = 0; i < n; ++i) {
            nums[a[i].second] = i;
        }
        SegmentTree tree(n);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i) {
            ans[i] = tree.count(0, nums[i] - 1, 0, 0, n - 1);
            tree.insert(nums[i], 0, 0, n - 1);
        }
        return move(ans);
    }
};

int main() {
    Solution s;

    return 0;
}