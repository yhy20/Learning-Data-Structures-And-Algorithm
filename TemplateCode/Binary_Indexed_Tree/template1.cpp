//维护原数组：单点修改，区间查询
//维护差分数组：区间修改，单点查询
template <typename T>
class BIT {
public:
    BIT(int n) : n(n), c(n + 1) {}
    //单点修改
    void add(int p, T x) {
        for(int i = p; i <= n; i += lowbit(i)) c[i] += x;
    }
    //区间修改
    void add(int l, int r, T x) {
        add(l, x);
        add(r + 1, -x);
    }
    //求[1, x]的值
    T sum(int p) {
        T ret = 0;
        for(int i = p; i >= 1; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    //求闭区间[l, r]的值
    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    int kth(T x) {
        int ret = 0;
        for(int i = 1 << 20; i >= 1; i >>= 1)
            if(ret + i < n && c[ret + i] < x) {
                ret += i;
                x -= c[ret];
            }
        return ret + 1;
    }

private:
    int n;
    vector<T> c;
    static int lowbit(int x) { return x & -x; }
};

