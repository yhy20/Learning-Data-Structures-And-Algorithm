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
typedef vector<VI> VII;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;
//拓扑排序解决
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        VI inDegree(n);
        VII g(n);
        for(auto e : edges) {
            g[e[0]].pb(e[1]);
            g[e[1]].pb(e[0]);
            ++inDegree[e[0]];
            ++inDegree[e[1]];
        }
        queue<int> q;
        rep(i, 0, n) if(inDegree[i] == 1) {
            inDegree[i] = 0;
            q.push(i);
        }
        int num = n, level = 0;
        while(num > 2) {
            int k = q.size();
            rep(i, 0, k) {
                int u = q.front();
                q.pop();
                --num;
                for(auto v : g[u]) {
                    if(--inDegree[v] == 1) {
                        inDegree[v] = 0;
                        q.push(v);
                    }
                }
            }
            level++;
        }
        return num == 2 ? level * 2 + 1 : level * 2;
    }
};

int main() {
    Solution s;

    return 0;
}