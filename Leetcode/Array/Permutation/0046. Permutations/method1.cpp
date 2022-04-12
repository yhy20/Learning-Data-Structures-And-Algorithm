#include <bits/stdc++.h>
using namespace std;

// dfs
class Solution {
public:
    vector<int> seen;
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        seen.assign(nums.size(), false);
        dfs(nums, nums.size());
        return move(ans);
    }
    void dfs(vector<int>& nums, int n) {
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; ++i) {
            if(seen[i]) continue;
            seen[i] = true;
            temp.emplace_back(nums[i]);
            dfs(nums, n);
            temp.pop_back();
            seen[i] = false;
        }
    }
};

int main() {
    Solution s;

    return 0;
}