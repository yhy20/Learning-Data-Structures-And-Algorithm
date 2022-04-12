#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        bool hash1[101][101] = {0};
        bool hash2[101][101] = {0};
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(hash1[i][matrix[i][j]] || hash2[j][matrix[i][j]]) {
                    return false;
                }
                hash1[i][matrix[i][j]] = true;
                hash2[j][matrix[i][j]] = true;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}