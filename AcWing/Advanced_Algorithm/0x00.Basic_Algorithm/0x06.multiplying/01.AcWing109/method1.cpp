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

//单个case时间复杂度nlog^2(n)
//优化后可以达到nlog(n)
//本解法运行12s，超过了时间限制10s，在copy，sort需要优化
const int N = 500005;
int n, m, a[N], b[N];
ll t;
bool check(int l, int r) {
    copy(a + l, a + r + 1, b + l);
    sort(b + l, b + r + 1);
    int x = l, y = r, c = 0;
    ll sum = 0;
    while(x < y && c++ < m) {
        sum += pow(b[y--] - b[x++], 2);
        if(sum > t) return false;
    }
    return true;
}

int main() {
    ios;
    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> m >> t;
        rep(i, 0, n) cin >> a[i];
        int l = 0, ans = 0;
        //使用的闭区间[l, r]
        while(l < n) {
            int p = 1, r = l;
            while(p) {
                if(r + p < n && check(l, r + p)) {
                    r += p;
                    p <<= 1;
                } else {
                    p >>= 1;
                }
            }
            l = r + 1;
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
