#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j, m, n);
                    ++ans;
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        grid[x][y] = '0';
        for(int k = 0; k < 4; ++k) {
            int nx = x + dirs[k][0];
            int ny = y + dirs[k][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                bfs(grid, nx, ny, m, n);
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}