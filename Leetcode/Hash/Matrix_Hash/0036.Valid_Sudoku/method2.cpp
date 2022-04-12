#include <bits/stdc++.h>
using namespace std;

//位优化
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int square[9] = {0}, row[9] = {0}, col[9] = {0};
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int index = (i / 3) * 3 + j / 3;
                    int num = 1 << (board[i][j] - '1');
                    if((square[index] & num) || (row[i] & num) || (col[j] & num)) {
                        return false;
                    }
                    square[index] |= num;
                    row[i] |= num;
                    col[j] |= num;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}