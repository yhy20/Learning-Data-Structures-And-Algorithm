#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size());
#define pb push_back
#define mp make_pair
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

int main() {
    ios;
    int n, m;
    cin >> n >> m;
    vector<PII> a(n), b(m);
    rep(i, 0, n) cin >> a[i].fi >> a[i].se;
    rep(i, 0, m) cin >> b[i].fi >> b[i].se;
    sort(all(a), [](auto& l, auto& r) -> bool {
        return l.fi > r.fi;
    });
    sort(all(b), [](auto& l, auto& r) -> bool {
        return l.fi > r.fi;
    });
    int ans = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(a[i].fi <= b[j].fi && a[i].se >= b[j].fi && b[j].se > 0) {
                --b[j].se;
                ++ans;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}