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

// Forward declaration of compare API.
bool compare(int a, int b);
// return bool means whether a is less than b.
class Solution {
public:
    vector<int> specialSort(int n) {
        vector<int> ans(n + 1);
        rep(i, 1, n + 1) ans[i] = i;
        rep(i, 2, n + 1) {
            int l = 1, r = i;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(compare(ans[mid], i))
                    l = mid + 1;
                else
                    r = mid;
            }
            per(j, l + 1, i + 1) {
                ans[j] = ans[j - 1];
            }
            ans[l] = i;
        }
        return vector<int>(ans.begin() + 1, ans.end());
    }
};