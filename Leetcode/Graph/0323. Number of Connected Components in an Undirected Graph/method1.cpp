#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> seen;
    int countComponents(int n, vector<vector<int>>& edges) {
        seen.assign(n, false);
        vector<forward_list<int>> graph(n, forward_list<int>());
        for(auto& e : edges) {
            graph[e[0]].push_front(e[1]);
            graph[e[1]].push_front(e[0]);
        }
        int ans = 0;
        for(int u = 0; u < n; ++u) {
            if(!seen[u]) {
                dfs(graph, u);
                ++ans;
            }
        }
        return ans;
    }
    void dfs(vector<forward_list<int>>& graph, int u) {
        seen[u] = true;
        for(auto v : graph[u]) {
            if(!seen[v]) {
                dfs(graph, v);
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}