#include<bits/stdc++.h>
using namespace std;

//9 * 9 普通hash
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool square[9][9] = {0}, row[9][9] = {0}, col[9][9] = {0};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int index = (i / 3) * 3 + j / 3;
                    int num = board[i][j] - '1';
                    if(square[index][num] || row[i][num] || col[j][num]){
                        return false;
                    }
                    square[index][num] = true;            
                    row[i][num] = true;
                    col[j][num] = true;
                }     
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    
    return 0;
}