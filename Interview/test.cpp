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
    
int n, m;

namespace LazySegTree {
    #define lson o * 2, l, (l + r) / 2
    #define rson o * 2 + 1, (l + r) / 2 + 1, r
    const int SET_VAL = 0;
    const int INIT_VAL = 0;
    struct Q {
        int setv;
        explicit Q(int setv = SET_VAL) : setv(setv) {}
        void operator+=(const Q& q) {
            if(q.setv != SET_VAL) setv += q.setv;
        }
    };
    struct P {
        int val;
        explicit P(int val = INIT_VAL) : val(val) {}
        void up(Q& q) {
            if(q.setv != SET_VAL) val += q.setv;
        }
    };
    template <typename T>
    P operator&(T&& a, T&& b) {
        return P(a.val+ b.val);
    }
    const int MAX_N = 1e5;
    P p[MAX_N << 2];
    Q q[MAX_N << 2];
    void up(int o, int l, int r) {
        if(l == r)
            p[o] = P();
        else
            p[o] = p[o * 2] & p[o * 2 + 1];
        p[o].up(q[o]);
    }
    void down(int o, int l, int r) {
        q[o * 2] += q[o];
        q[o * 2 + 1] += q[o];
        q[o] = Q();
        up(lson);
        up(rson);
    }
    template <typename T>
    void build(T&& f, int o = 1, int l = 1, int r = n) {
        if(l == r)
            q[o] = f(l);
        else {
            build(f, lson);
            build(f, rson);
            q[o] = Q();
        }
        up(o, l, r);
    }
    P query(int ql, int qr, int o = 1, int l = 1, int r = n) {
        if(ql > r || l > qr) return P();
        if(ql <= l && r <= qr) return p[o];
        down(o, l, r);
        return query(ql, qr, lson) & query(ql, qr, rson);
    }
    void update(int ql, int qr, const Q& x, int o = 1, int l = 1, int r = n) {
        if(ql > r || l > qr) return;
        if(ql <= l && r <= qr)
            q[o] += x;
        else {
            down(o, l, r);
            update(ql, qr, x, lson);
            update(ql, qr, x, rson);
        }
        up(o, l, r);
    }
}

using namespace LazySegTree;



int main(){
    cin>>n>>m;
    rep(i,1,n+1){
        int x;
        cin>>x;
        update(i,i,Q(x));
    }

    rep(i,1,m+1){
        char c;
        cin>>c;
        if(c=='C'){
            int l, r, d;
            cin>>l>>r>>d;
            update(l,r,Q(d));
        }else{
            int l, r;
            cin>>l>>r;
            cout<<query(l,r).val<<' ';
        }
    }
    return 0;
}
