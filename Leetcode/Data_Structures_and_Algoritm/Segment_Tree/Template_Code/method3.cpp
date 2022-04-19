template <typename T>
T op_min(T a, T b) { return min(a, b); }

template <typename T>
T op_max(T a, T b) { return max(a, b); }

template <typename T>
T op_sum(T a, T b) { return a + b; }

template <typename T>
T init_val() { return T(0); }

// Segment Tree
template <typename T, T (*op)(T, T), T (*e)()>
class SegTree {
public:
    explicit SegTree(int n) : n(n), d(n * 4, e()) {
        assert(n > 0);
        d = std::vector<T>(n * 4, e());
    }
    explicit SegTree(const std::vector<T>& v) : n(int(v.size())) {
        d = std::vector<T>(n * 4, e());
        build(0, v, 0, n - 1);
    }
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
    void change(int p, int idx, T x, int l, int r) {
        if(l == r) {
            d[p] = x;
            return;
        }
        int mid = l + ((r - l) >> 1);
        int lchild = p * 2 + 1, rchild = p * 2 + 2;
        if(idx <= mid) {
            change(lchild, idx, x, l, mid);
        } else {
            change(rchild, idx, x, mid + 1, r);
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
    T all_range() { return range(0, 0, n - 1, 0, n - 1); }

private:
    int n;
    std::vector<T> d;
};