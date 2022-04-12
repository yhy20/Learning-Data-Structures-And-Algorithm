#include <bits/stdc++.h>
using namespace std;

//多源bfs+位图记录每一条走过的路径，当有一条路径经过所有点时最短路径找到
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>> seen(n, vector<bool>(1 << n));
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }
        int dist = (1 << n) - 1;
        while(!q.empty()) {
            auto [u, musk, step] = q.front();
            q.pop();
            if(musk == dist) return step;
            for(auto v : graph[u]) {
                int musk_v = musk | (1 << v);
                if(!seen[v][musk_v]) {
                    q.emplace(v, musk_v, step + 1);
                    seen[v][musk_v] = true;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}