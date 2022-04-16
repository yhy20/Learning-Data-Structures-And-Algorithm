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

class Solution {
public:
    int maximumProduct(vector<int>& a, int k) {
        int n = a.size();
        sort(all(a));
        vector<ll> b(n);
        b[0] = a[0];
        rep(i, 1, n) b[i] = b[i - 1] + a[i];
        int l = -1, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(k >= ll(mid + 1) * a[mid] - b[mid])
                l = mid;
            else
                r = mid - 1;
        }
        if(l > -1) {
            k -= (ll(l + 1) * a[l] - b[l]);
            int t = a[l] + k / (l + 1);
            int m = k % (l + 1);
            rep(i, 0, l + 1) a[i] = (m-- > 0) ? t + 1 : t;
        }
        ll ans = 1;
        rep(i, 0, n) ans = ans * a[i] % mod;
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}