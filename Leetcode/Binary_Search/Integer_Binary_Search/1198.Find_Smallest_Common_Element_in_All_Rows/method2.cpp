#include <bits/stdc++.h>
using namespace std;

// 二分查找
class Solution1 {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        for (auto num : mat[0]) {
            bool flag = true;
            for (int i = 1; i < mat.size(); ++i) {
                auto itr = lower_bound(mat[i].begin(), mat[i].end(), num);
                if (itr == mat[i].end()) return -1;
                if (*itr != num) {
                    flag = false;
                    break;
                }
            }
            if (flag) return num;
        }
        return -1;
    }
};

// 二分查找起始位置优化
class Solution {
public:
    int smallestCommonElement(vector<vector<int>> &mat) {
        int m = mat.size();
        vector<vector<int>::iterator> startAt(m);
        for (int i = 1; i < m; ++i)
            startAt[i] = mat[i].begin();
        for (auto num : mat[0]) {
            bool flag = true;
            for (int i = 1; i < m; ++i) {
                startAt[i] = lower_bound(startAt[i], mat[i].end(), num);
                if (startAt[i] == mat[i].end()) return -1;
                if (*startAt[i] != num) {
                    flag = false;
                    break;
                }
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