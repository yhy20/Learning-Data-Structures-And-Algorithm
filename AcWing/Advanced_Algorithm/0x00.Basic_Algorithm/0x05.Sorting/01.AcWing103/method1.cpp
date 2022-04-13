#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
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

//直接考虑map，不离散化
const int N = 200010;
map<int, int> a;
int n, m, b[N], c[N];
int main() {
    ios;
    cin >> n;
    int x;
    rep(i, 0, n) {
        cin >> x;
        a[x]++;
    }
    cin >> m;
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, m) cin >> c[i];
    int ans = 0;
    rep(i, 1, m) {
        if(a[b[i]] > a[b[ans]] || (a[b[i]] == a[b[ans]] && a[c[i]] > a[c[ans]])) ans = i;
    }
    cout << ans + 1 << '\n';
    return 0;
}