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
    int findClosestNumber(vector<int>& nums) {
        int ans = 0x3f3f3f3f;
        for(auto num : nums) {
            if(abs(ans - 0) > abs(num - 0) || abs(ans - 0) == abs(num - 0) && num > ans) {
                ans = num;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}