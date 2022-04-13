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
int n, a[100010];
int main() {
    ios;
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int mid = a[n / 2];
    ll ans = 0;
    rep(i, 0, n) ans += abs(a[i] - mid);
    cout << ans;
    return 0;
}