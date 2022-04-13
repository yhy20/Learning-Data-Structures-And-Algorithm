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

int n;
ll a[100005];
int main() {
    ios;
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    per(i, 1, n) a[i] -= a[i - 1];
    ll x = 0, y = 0;
    rep(i, 1, n) {
        if(a[i] > 0)
            x += a[i];
        else
            y += a[i];
    }
    y = abs(y);
    cout << max(x, y) << '\n';
    cout << abs(x - y) + 1 << '\n';
    return 0;
}