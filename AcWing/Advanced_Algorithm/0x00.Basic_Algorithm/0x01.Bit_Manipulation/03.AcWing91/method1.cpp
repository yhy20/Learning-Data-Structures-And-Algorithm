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

int n;
int g[20][20];
int main() {
    ios;
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> g[i][j];
    int dp[1 << n][n];
    ms(dp, 0x3f);
    dp[1][0] = 0;
    rep(i, 0, 1 << n) {
        rep(j, 0, n) {
            if((i >> j) & 1) {
                rep(k, 0, n) {
                    if(((i ^ (1 << j)) >> k) & 1) {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + g[k][j]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
    return 0;
}