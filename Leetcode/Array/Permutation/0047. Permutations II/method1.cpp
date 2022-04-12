#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> seen;
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        seen.assign(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, nums.size());
        return move(ans);
    }
    void dfs(vector<int>& nums, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(seen[i] || (i > 0 && nums[i] == nums[i - 1] && !seen[i - 1]))
                continue;
            seen[i] = true;
            temp.emplace_back(nums[i]);
            dfs(nums, n);
            temp.pop_back();
            seen[i] = false;
        }
    }
};

int main(){
    Solution s;
    
    return 0;
}