#include <bits/stdc++.h>
using namespace std;

// Binary Indexed Tree
class BIT {
private:
    int n;
    vector<pair<int, int>> tree;

public:
    BIT(int _n) : n(_n), tree(n + 1) {}
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int x, int val) {
        tree[x].second = val;
        while(x <= n) {
            tree[x].first += val;
            x += lowbit(x);
        }
    }
    void change(int x, int val) {
        int pre = tree[x].second;
        tree[x].second = val;
        while(x <= n) {
            tree[x].first += val - pre;
            x += lowbit(x);
        }
    }
    int query(int x) {
        int ret = 0;
        while(x) {
            ret += tree[x].first;
            x -= lowbit(x);
        }
        return ret;
    }
};

class NumArray {
public:
    BIT bit;
    NumArray(vector<int>& nums) : bit(nums.size()) {
        for(int i = 0; i < nums.size(); ++i) {
            bit.update(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        bit.change(index + 1, val);
    }

    int sumRange(int left, int right) {
        return bit.query(right + 1) - bit.query(left);
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 6};
    NumArray s(a);

    return 0;
}