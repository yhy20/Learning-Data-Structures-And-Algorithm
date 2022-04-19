//维护原数组：单点修改，区间查询
//维护差分数组：区间修改，单点查询
template <typename T>
class BIT {
public:
    BIT(int n) : n(n), c(n + 1) {}
    //单点修改
    void add(int x, T v) {
        for(int i = x; i <= n; i += lowbit(i)) c[i] += v;
    }
    //区间修改
    void add(int l, int r, T v) {
        add(l, v);
        add(r + 1, -v);
    }
    //求[1, x]的值
    T sum(int x) {
        T ret = 0;
        for(int i = x; i >= 1; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    //求闭区间[l, r]的值
    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    int kth(T v) {
        int ret = 0;
        for(int i = 1 << 20; i >= 1; i >>= 1)
            if(ret + i < n && c[ret + i] < v) {
                ret += i;
                v -= c[ret];
            }
        return ret + 1;
    }

private:
    int n;
    vector<T> c;
    static int lowbit(int x) { return x & -x; }
};