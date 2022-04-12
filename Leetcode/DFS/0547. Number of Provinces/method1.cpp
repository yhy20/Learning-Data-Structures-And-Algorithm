#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n = 0;
    vector<bool> seen;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        n = isConnected.size();
        seen.assign(n, false);
        for(int u = 0; u < n; ++u) {
            if(!seen[u]) {
                ++ans;
                dfs(u, isConnected);
            }
        }
        return ans;
    }
    void dfs(int u, vector<vector<int>>& isConnected) {
        seen[u] = true;
        for(int v = 0; v < n; ++v) {
            if(u != v && isConnected[u][v] && !seen[v]) {
                dfs(v, isConnected);
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}