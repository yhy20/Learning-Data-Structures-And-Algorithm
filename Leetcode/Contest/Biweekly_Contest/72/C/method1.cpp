#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size());
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long k) {
        if(k & 1) return {};
        ll n = sqrt(k);
        while(n * (n + 1) < k) ++n;
        vector<ll> ans;
        ll ep = (n * (n + 1) - k) / 2;
        rep(i, 1, n + 1) {
            if(i != ep) ans.pb(i * 2);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}