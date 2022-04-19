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
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<PII> a(n);
        rep(i, 0, n) {
            a[i].fi = nums[i];
            string str;
            while(nums[i]) {
                str += mapping[nums[i] % 10] + '0';
                nums[i] /= 10;
            }
            if(str == "") {
                a[i].se = mapping[0];
                continue;
            }
            reverse(all(str));
            a[i].se = stoi(str);
        }
        sort(all(a), [](auto& l, auto& r) {
            return l.se < r.se;
        });
        VI ans(n);
        rep(i, 0, n) ans[i] = a[i].fi;
        return move(ans);
    }
};

int main() {
    Solution s;

    return 0;
}