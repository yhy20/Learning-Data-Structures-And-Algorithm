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
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int n = total / cost1;
        ll ans = 0;
        rep(i, 0, n + 1) {
            ans += (total - i * cost1) / cost2 + 1;
        }
        return ans;
    }
};
int main() {
    Solution s;

    return 0;
}