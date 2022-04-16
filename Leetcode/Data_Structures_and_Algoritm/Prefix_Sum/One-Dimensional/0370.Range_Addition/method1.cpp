#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length);
        for(auto v : updates){
            ans[v[0]] += v[2];
            if(v[1] < length - 1){
                ans[v[1] + 1] -= v[2];
            }
        }
        partial_sum(ans.begin(),ans.end(),ans.begin());
        return move(ans);
    }
};

int main(){
    Solution s;
    
    return 0;
}