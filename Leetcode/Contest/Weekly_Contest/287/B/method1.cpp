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
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        unordered_map<int, int> map;
        for(auto& elem : a) {
            map[elem[0]];
            map[elem[1]]--;
        }
        vector<vector<int>> ans(2, vector<int>());
        for(auto& [key, val] : map) {
            if(val == 0) {
                ans[0].pb(key);
            } else if(val == -1) {
                ans[1].pb(key);
            }
        }
        sort(all(ans[0]));
        sort(all(ans[1]));
        return move(ans);
    }
};

int main() {
    Solution s;

    return 0;
}