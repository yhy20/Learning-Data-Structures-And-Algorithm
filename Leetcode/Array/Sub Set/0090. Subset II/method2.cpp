#include <bits/stdc++.h>
using namespace std;

//排序去重 + 回溯
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, false);
        return move(ans);
    }
    void dfs(vector<int>& nums, int i, bool pre) {
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        dfs(nums, i + 1, false);
        if(i != 0 && nums[i] == nums[i - 1] && !pre) {
            return;
        }
        temp.push_back(nums[i]);
        dfs(nums, i + 1, true);
        temp.pop_back();
    }
};

int main() {
    Solution s;

    return 0;
}