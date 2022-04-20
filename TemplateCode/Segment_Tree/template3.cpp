template <typename T, T (*op)(T, T)>
class SegTree {
public:
    struct Node {
        int l, r;
        T val;
    };
    explicit SegTree(const std::vector<T>& v) : n(int(v.size())) {
        assert(v.size() > 0);
        d = std::vector<T>(n * 4);
        build(1, v, 1, n);
    }
    void set(int idx, T x) {
        assert(0 <= idx && idx < n);
        set(0, idx, x, 0, n - 1);
    }
    void add(int idx, T x) {
        assert(0 <= idx && idx < n);
        add(0, idx, x, 0, n - 1);
    }
    T range(int left, int right) {
        assert(0 <= left && left - 1 <= right && right < n);
        if(left == right + 1) return e();
        return range(0, left, right, 0, n - 1);
    }
    T all_range() { return d[1]; }

private:
    int n;
    std::vector<Node> d;
    void build(int p, const std::vector<T>& v, int l, int r) {
        d[p].l = l, dp[p].r = r;
        if(l == r) {
            d[p].val = v[l];
            return;
        }
        int mid = (l + r) >> 1;
        int lchild = p >> 1, rchild = p >> 1 | 1;
        build(lchild, v, l, mid);
        build(rchild, v, mid + 1, r);
        d[p] = op(d[lchild], d[rchild]);
    }

    void set(int p, int idx, T x, int l, int r) {
        if(l == r) {
            d[p] = x;
            return;
        }
        int mid = (l + r) >> 1;
        int lchild = p << 1 , rchild = p << 1 | 1;
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
            add(lchild, idx, x, l, mid);
        } else {
            add(rchild, idx, x, mid + 1, r);
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