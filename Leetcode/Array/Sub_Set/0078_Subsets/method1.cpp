#include <bits/stdc++.h>
using namespace std;

//迭代枚举、二重循环会跑满nums.size()次
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = 1 << nums.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(i & (1 << j)) {
                    temp.emplace_back(nums[j]);
                }
            }
            ans.push_back(move(temp));
        }
        return move(ans);
    }
};

//迭代枚举法优化，当t为0时提前结束循环，不跑满nums.size()次
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = 1 << nums.size();
        for(int i = 0; i < n; ++i) {
            int t = i, index = 0;
            while(t) {
                if(t & 1) temp.emplace_back(nums[index]);
                t >>= 1;
                ++index;
            }
            ans.push_back(move(temp));
        }
        return move(ans);
    }
};

int main() {
    Solution s;

    return 0;
}