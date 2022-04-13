#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
const ll mod = 1e9 + 7;

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

const int N = 5005;
int a[N][N];

int main() {
    ios;
    int n, r;
    cin >> n >> r;
    rep(i, 0, n) {
        int x, y, w;
        cin >> x >> y >> w;
        ++x;
        ++y;
        a[x][y] += w;
    }
    int ans = 0;
    rep(i, 1, N) {
        rep(j, 1, N) {
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    if(r >= 5000) {
        cout << a[N - 1][N - 1];
    } else {
        int ans = 0;
        rep(i, r, N) {
            rep(j, r, N) {
                ans = max(ans, a[i][j] - a[i - r][j] - a[i][j - r] + a[i - r][j - r]);
            }
        }
        cout << ans;
    }
    return 0;
}