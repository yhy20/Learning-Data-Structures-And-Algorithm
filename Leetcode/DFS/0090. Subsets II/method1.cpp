#include <bits/stdc++.h>
using namespace std;

//迭代法 + 去重
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = 1 << nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            bool flag = true;
            for(int j = 0; j < nums.size(); ++j) {
                if(i & (1 << j)) {
                    if(j > 0 && nums[j] == nums[j - 1] && !(1 << (j - 1) & i)) {
                        flag = false;
                        break;
                    }
                    temp.emplace_back(nums[j]);
                }
            }
            if(flag) ans.push_back(move(temp));
            temp.clear();
        }
        return move(ans);
    }
};

int main() {
    Solution s;

    return 0;
}