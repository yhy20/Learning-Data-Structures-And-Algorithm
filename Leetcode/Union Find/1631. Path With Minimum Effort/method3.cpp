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

// sort + 并查集
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<tuple<int, int, int>> a;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int hash = i * n + j;
                if(i > 0) a.emplace_back(hash - n, hash, abs(heights[i][j] - heights[i - 1][j]));
                if(j > 0) a.emplace_back(hash - 1, hash, abs(heights[i][j] - heights[i][j - 1]));
            }
        }
        sort(a.begin(), a.end(), [](const auto& l, const auto& r) {
            return get<2>(l) < get<2>(r);
        });
        UnionFind u(m * n);
        int ans = 0, start = 0, end = m * n - 1;
        for(const auto [x, y, d] : a) {
            u.unionSet(x, y);
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