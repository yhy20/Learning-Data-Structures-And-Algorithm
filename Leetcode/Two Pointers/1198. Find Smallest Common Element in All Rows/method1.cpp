#include <bits/stdc++.h>
using namespace std;

// hash计数, 逐行
class Solution1 {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (++mp[mat[i][j]] == m) {
                    return mat[i][j];
                }
            }
        }
        return -1;
    }
};

// hash计数, 逐列
class Solution {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> mp;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (++mp[mat[i][j]] == m) {
                    return mat[i][j];
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