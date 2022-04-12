#include <bits/stdc++.h>
using namespace std;

//递归法，每次选择或不选择数组中某个元素
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return move(ans);
    }
    void dfs(vector<int>& nums, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.emplace_back(nums[index]);
        dfs(nums, index + 1);
        temp.pop_back();

        dfs(nums, index + 1);
    }
};

int main() {
    Solution s;

    return 0;
}