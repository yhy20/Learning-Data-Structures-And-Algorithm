#include <bits/stdc++.h>
using namespace std;

// n指针
class Solution {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> p(m);
        for (auto num : mat[0]) {
            bool flag = true;
            for (int i = 1; i < m; ++i) {
                while (p[i] < n && mat[i][p[i]] < num)
                    ++p[i];
                if (p[i] == n) break;
                if (mat[i][p[i]] != num) flag = false;
            }
            if (flag) return num;
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}