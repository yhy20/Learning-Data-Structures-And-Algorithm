#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size());
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

template <typename T>
T op_min(T a, T b) { return min(a, b); }

template <typename T>
T op_max(T a, T b) { return max(a, b); }

template <typename T>
T op_sum(T a, T b) { return a + b; }

template <typename T>
T init_val() { return T(0); }

//递归实现的普适线段树，支持单点修改，单点增加，区间查询等操作。
//对区间的操作由op函数定义, init_val表示初始化值
template <typename T, T (*op)(T, T), T (*e)()>
class SegTree {
public:
    explicit SegTree(int n) : n(n), d(n * 4, e()) {
        assert(n > 0);
        d = std::vector<T>(n * 4, e());
    }
    explicit SegTree(const std::vector<T>& v) : n(int(v.size())) {
        assert(v.size() > 0);
        d = std::vector<T>(n * 4, e());
        build(0, v, 0, n - 1);
    }
    void set(int idx, T x) { set(0, idx, x, 0, n - 1); }
    void add(int idx, T x) { add(0, idx, x, 0, n - 1); }
    T range(int left, int right) { return range(0, left, right, 0, n - 1); }
    T all_range() { return d[0]; }

private:
    int n;
    std::vector<T> d;
    void build(int p, const std::vector<T>& v, int l, int r) {
        if(l == r) {
            d[p] = v[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        int lchild = p * 2 + 1, rchild = p * 2 + 2;
        build(lchild, v, l, mid);
        build(rchild, v, mid + 1, r);
        d[p] = op(d[lchild], d[rchild]);
    }
    void set(int p, int idx, T x, int l, int r) {
        if(l == r) {
            d[p] = x;
            return;
        }
        int mid = l + ((r - l) >> 1);
        int lchild = p * 2 + 1, rchild = p * 2 + 2;
        if(idx <= mid) {
            set(lchild, idx, x, l, mid);
        } else {
            set(rchild, idx, x, mid + 1, r);
        }
        d[p] = op(d[lchild], d[rchild]);
    }

    void add(int p, int idx, T x, int l, int r) {
        if(l == r) {
            d[p] += x;
            return;
        }
        int mid = l + ((r - l) >> 1);
        int lchild = p * 2 + 1, rchild = p * 2 + 2;
        if(idx <= mid) {
            set(lchild, idx, x, l, mid);
        } else {
            set(rchild, idx, x, mid + 1, r);
        }
        d[p] = op(d[lchild], d[rchild]);
    }

    T range(int p, int left, int right, int l, int r) const {
        if(left <= l && right >= r) return d[p];
        int mid = l + ((r - l) >> 1);
        int lchild = p * 2 + 1, rchild = p * 2 + 2;
        if(right <= mid) {
            return range(lchild, left, right, l, mid);
        } else if(left > mid) {
            return range(rchild, left, right, mid + 1, r);
        } else {
            return op(range(lchild, left, right, l, mid), range(rchild, left, right, mid + 1, r));
        }
    }
};

class NumArray {
public:
    int n;
    SegTree<int, op_sum<int>, init_val<int>> tree;
    NumArray(vector<int>& nums) : n(nums.size()), tree(nums) {}

    void update(int index, int val) {
        tree.set(index, val);
    }

    int sumRange(int left, int right) {
        return tree.range(left, right);
    }
};

int main() {
    ios;
    
    return 0;
}