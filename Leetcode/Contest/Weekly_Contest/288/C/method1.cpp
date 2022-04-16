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
        vector<ll> b(n + 1);
        rep(i, 1, n + 1) b[i] = b[i - 1] + a[i - 1];
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(k >= ll(mid) * a[mid - 1] - b[mid])
                l = mid;
            else
                r = mid - 1;
        }
        if(l > 0) {
            k -= (ll(l) * a[l - 1] - b[l]);
            int t = a[l - 1] + k / l;
            int m = k % l;
            rep(i, 0, l) a[i] = (m-- > 0) ? t + 1 : t;
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