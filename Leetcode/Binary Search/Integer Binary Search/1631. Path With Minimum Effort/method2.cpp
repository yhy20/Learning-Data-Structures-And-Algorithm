#include <bits/stdc++.h>
using namespace std;

//路径压缩并查集
class UnionFind {
public:
    vector<int> f;
    UnionFind(int n) : f(n) {
        for(int i = 0; i < n; ++i) f[i] = i;
    }
    int find(int x) {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    void unionSet(int x, int y) {
        f[find(x)] = find(y);
    }
};

//并查集 + 优先级队列
class Solution {
public:
    struct State {
        int p1, p2, d;
        State(int _p1, int _p2, int _d) : p1(_p1), p2(_p2), d(_d) {}
        bool operator>(const State& r) const {
            return this->d > r.d;
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<State, vector<State>, greater<State>> minHeap;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int hash = i * n + j;
                if(i > 0) minHeap.emplace(hash - n, hash, abs(heights[i - 1][j] - heights[i][j]));
                if(j > 0) minHeap.emplace(hash - 1, hash, abs(heights[i][j - 1] - heights[i][j]));
            }
        }
        int ans = 0;
        UnionFind u(m * n);
        int start = 0, end = m * n - 1;
        while(!minHeap.empty()) {
            auto [p1, p2, d] = minHeap.top();
            minHeap.pop();
            u.unionSet(p1, p2);
            if(u.isConnected(start, end)) {
                ans = d;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}