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

int n, f, a[100010];
db sum[100010];

bool check(double d) {
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (a[i] - d);
    }

    db minv = 0;
    for(int i = 0, j = f; j <= n; j++, i++) {
        minv = min(minv, sum[i]);
        if(sum[j] - minv >= 0) return true;
    }
    return false;
}

//实数二分精度问题
int main() {
    ios;
    cin >> n >> f;
    rep(i, 1, n + 1) cin >> a[i];
    db l = 1, r = *max_element(a + 1, a + n + 1);
    while(r - l > 1e-5) {
        db mid = l + ((r - l) / 2);
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << int(r * 1000);
    return 0;
}