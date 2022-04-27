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
    unordered_map<int, bool> mp;
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        auto dist = [](int i, int j, int x, int y) -> int {
            return (i - x) * (i - x) + (j - y) * (j - y);
        };
        for(auto& v : circles) {
            int x = v[0], y = v[1], r = v[2];
            rep(j, y - r, y + r + 1) {
                rep(i, x - r, x + r + 1) {
                    if(dist(i, j, x, y) <= r * r) {
                        if(!mp.count(i * 1000 + j)) {
                            ++ans;
                            mp[i * 1000 + j] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    // Solution s;

    return 0;
}