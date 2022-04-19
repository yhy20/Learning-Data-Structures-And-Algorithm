#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
    bool check(vector<int>& a, int d, ll k) {
        ll sum = 0;
        for(auto num : a) {
            sum += int(num / d);
        }
        return sum >= k;
    }
    int maximumCandies(vector<int>& a, ll k) {
        int l = 0, r = 1e7;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(check(a, mid, k)) {
                l = mid;
            } else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    Solution s;

    return 0;
}