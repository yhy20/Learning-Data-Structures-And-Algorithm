#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size());
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;

template <typename T>
T op_min(T a, T b) { return min(a, b); }

template <typename T>
T op_max(T a, T b) { return max(a, b); }

template <typename T>
T op_sum(T a, T b) { return a + b; }

template <typename T>
T init_val() { return T(0); }

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
    void change(int p, T x) {
        assert(0 <= p && p < n);
        p += size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }
    // return d[p];
    T get(int p) const {
        assert(0 <= p && p < n);
        return d[p + size];
    }
    // if l != r return op(d[l], ..., d[r - 1])
    // if l == r return e()
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
    // if n != 0 return op(d[0], ..., d[n - 1])
    // if n == 0 return e()
    T all_range() const { return d[1]; }

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

int main() {
    return 0;
}