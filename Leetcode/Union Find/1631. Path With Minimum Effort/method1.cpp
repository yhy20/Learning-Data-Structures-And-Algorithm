#include <bits/stdc++.h>
using namespace std;

// binarySearch + bfs
class Solution {
public:
    int m = 0, n = 0;
    bool seen[101][101];
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool check(vector<vector<int>>& a, int d) {
        memset(seen, 0, sizeof(seen));
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        seen[0][0] = true;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; ++k) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny] && abs(a[nx][ny] - a[x][y]) <= d) {
                    if(nx == m - 1 && ny == n - 1) return true;
                    q.emplace(nx, ny);
                    seen[nx][ny] = true;
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& a) {
        m = a.size();
        n = a[0].size();
        if(m == 1 && n == 1) return 0;
        int l = 0, r = 1e6, ans = -1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(check(a, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}