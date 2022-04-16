#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirs[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    int m = 0, n = 0;
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> ans;
        m = land.size();
        n = land[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(land[i][j] == 0) {
                    ans.push_back(bfs(land, i, j));
                }
            }
        }
        sort(ans.begin(), ans.end());
        return move(ans);
    }
    int bfs(vector<vector<int>>& land, int x, int y) {
        land[x][y] = 1;
        int ret = 1;
        for(int i = 0; i < 8; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && land[nx][ny] == 0) {
                ret += bfs(land, nx, ny);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;

    return 0;
}