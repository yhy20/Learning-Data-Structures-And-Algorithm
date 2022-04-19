template <typename T>
T op_min(T a, T b) { return min(a, b); }

template <typename T>
T op_max(T a, T b) { return max(a, b); }

template <typename T>
T op_sum(T a, T b) { return a + b; }

template <typename T>
T init_val() { return T(0); }

//迭代实现的普适线段树，支持单点修改，单点增加，区间查询等操作。
//对区间的操作由op函数定义, init_val表示初始化值
template <typename T, T (*op)(T, T), T (*e)()>
class SegTree {
public:
    explicit SegTree(int n) : n(n) {
        assert(n >= 0);
        log = ceil_pow2(n);
        size = 1 << log;
        d = std::vector<T>(2 * size, e());
    }
    explicit SegTree(const std::vector<T>& v) : n(int(v.size())) {
        log = ceil_pow2(n);
        size = 1 << log;
        d = std::vector<T>(2 * size, e());
        for(int i = 0; i < n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
    // set d[p] = x
    void set(int p, T x) {
        assert(0 <= p && p < n);
        p += size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }
    // set d[p] = d[p] + x
    void add(int p, T x) {
        assert(0 <= p && p < n);
        p += size;
        d[p] += x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }
    // return d[p];
    T get(int p) const {
        assert(0 <= p && p < n);
        return d[p + size];
    }
    // if l == r return e()
    // if l != r return op(d[l], ..., d[r - 1])
    T range(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        T sml = e(), smr = e();
        l += size;
        r += size;

        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    // if n == 0 return e()
    // if n != 0 return op(d[0], ..., d[n - 1])
    T all_range() const { return d[1]; }

    //
    template <bool (*f)(T)>
    int max_right(int l) const {
        return max_right(l, [](T x) { return f(x); });
    }
    template <class F>
    int max_right(int l, F f) const {
        assert(0 <= l && l <= n);
        assert(f(e()));
        if(l == n) return n;
        l += size;
        T sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, d[l]))) {
                while(l < size) {
                    l = (2 * l);
                    if(f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return n;
    }

    template <bool (*f)(T)>
    int min_left(int r) const {
        return min_left(r, [](T x) { return f(x); });
    }
    template <class F>
    int min_left(int r, F f) const {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if(r == 0) return 0;
        r += size;
        T sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(op(d[r], sm))) {
                while(r < size) {
                    r = (2 * r + 1);
                    if(f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

private:
    int n, size, log;
    std::vector<T> d;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    int ceil_pow2(int n) {
        int x = 0;
        while((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
};
