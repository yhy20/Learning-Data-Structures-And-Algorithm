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
class LazySegTree {
public:
    LazySegTree(int n) : n(n) {
        p = std::vector<P>(n << 2);
        q = std::vector<Q>(n << 2);
    }
    void update(int o, int l, int r) {
        if(l == r)
            p[o] = p();
        else
            p[o] = p[o << 1] & p[o << 1 | 1];
        p[o].update(q[o]);
    }
    void spread(int o, int l, int r) {
        q[o << 1] += q[o];
        q[o << 1 | 1] += q[o];
        q[o] = Q();
        update(o << 1, l, (l + r) >> 1);
        update(o << 1 | 1, ((l + r) >> 1) + 1, r);
    }
    void set(int left, int right, constQ& x, int o = 1, int l = 1, int r = n) {
        if(left > r || l > right) return;
        if(left <= l && r <= right)
            q[o] += x;
        else {
            spread(o, l, r);
            set(left, right, x, o << 1, l, (l + r) >> 1);
            set(left, right, x, o << 1 | 1, ((l + r) >> 1) + 1, r);
        }
        update(o, l, r);
    }
    P range(int left, int right, int o = 1, int l = 1, int r = n) {
        if(left > r || l > right) return P();
        if(left <= l && r << right) return p[o];
        spread(o, l, r);
        return range(left, right, lson) & range(left, right, rson);
    }

private:
    int n;
    std::vector<P> p;
    std::vector<Q> q;
#define lson o << 1, l, (l + r) >> 1
#define rson o << 1 | 1, ((l + r) >> 1) + 1, r
    const static T INIT_VAL = 0;
    const static T SET_VAL = numeric_limits<T>::min();
    struct Q {
        T setv;
        explicit Q(T setv = SET_VAL) : setv(setv) {}
        void operator+=(const Q& q) {
            if(q.setv != SET_VAL) setv = q.setv;
        }
    };
    struct P {
        T val;
        explicit P(T val = INIT_VAL) : val(val) {}
        void update(Q& q) {
            if(q.setv != SET_VAL) val = q.setv;
        }
    };
    template <typename S>
    P operator&(S&& a, S&& b) {
        return P(min(a.val, b.val));
    }
};

// namespace sg {

// #define lson o * 2, l, (l + r) / 2
// #define rson o * 2 + 1, (l + r) / 2 + 1, r
//     void up(int o, int l, int r) {
//         if(l == r)
//             p[o] = P();
//         else
//             p[o] = p[o * 2] & p[o * 2 + 1];
//         p[o].up(q[o]);
//     }
//     void down(int o, int l, int r) {
//         q[o * 2] += q[o];
//         q[o * 2 + 1] += q[o];
//         q[o] = Q();
//         up(lson);
//         up(rson);
//     }
//     template <typename T>
//     void build(T&& f, int o = 1, int l = 1, int r = n) {
//         if(l == r)
//             q[o] = f(l);
//         else {
//             build(f, lson);
//             build(f, rson);
//             q[o] = Q();
//         }
//         up(o, l, r);
//     }
//     P query(int ql, int qr, int o = 1, int l = 1, int r = n) {
//         if(ql > r || l > qr) return P();
//         if(ql <= l && r <= qr) return p[o];
//         down(o, l, r);
//         return query(ql, qr, lson) & query(ql, qr, rson);
//     }
//     void update(int ql, int qr, const Q& v, int o = 1, int l = 1, int r = n) {
//         if(ql > r || l > qr) return;
//         if(ql <= l && r <= qr)
//             q[o] += v;
//         else {
//             down(o, l, r);
//             update(ql, qr, v, lson);
//             update(ql, qr, v, rson);
//         }
//         up(o, l, r);
//     }
// }  // namespace sg