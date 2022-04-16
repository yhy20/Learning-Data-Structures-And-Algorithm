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
    vector<int> sortEvenOdd(vector<int>& nums) {
        VI a, b;
        rep(i, 0, nums.size()) {
            if(i & 1)
                b.pb(nums[i]);
            else
                a.pb(nums[i]);
        }
        sort(all(a));
        sort(rall(b));
        int t1 = 0, t2 = 0;
        rep(i, 0, nums.size()) {
            nums[i] = i & 1 ? b[t2++] : a[t1++];
        }
        return move(nums);
    }
};

int main() {
    Solution s;

    return 0;
}