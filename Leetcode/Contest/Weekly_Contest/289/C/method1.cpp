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
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> r2(n + 1), r5(n + 1), c2(n + 1), c5(n + 1);
        rep(i, 0, n + 1) r2[i] = r5[i] = c2[i] = c5[i] = vector<int>(m + 1);
        rep(i, 1, n + 1) rep(j, 1, m + 1) {
            int x = grid[i - 1][j - 1];
            int two = 0, five = 0;
            while(x % 2 == 0) ++two, x /= 2;
            while(x % 5 == 0) ++five, x /= 5;
            r2[i][j] = r2[i][j - 1] + two;
            c2[i][j] = c2[i - 1][j] + two;
            r5[i][j] = r5[i][j - 1] + five;
            c5[i][j] = c5[i - 1][j] + five;
        }
        int ans = 0;
        rep(i, 1, n + 1) rep(j, 1, m + 1) {
            ans = max(ans, min(r2[i][j] + c2[i - 1][j], r5[i][j] + c5[i - 1][j]));
            ans = max(ans, min(r2[i][j] + c2[n][j] - c2[i][j], r5[i][j] + c5[n][j] - c5[i][j]));
            ans = max(ans, min(r2[i][m] - r2[i][j - 1] + c2[i - 1][j], r5[i][m] - r5[i][j - 1] + c5[i - 1][j]));
            ans = max(ans, min(r2[i][m] - r2[i][j - 1] + c2[n][j] - c2[i][j], r5[i][m] - r5[i][j - 1] + c5[n][j] - c5[i][j]));
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}