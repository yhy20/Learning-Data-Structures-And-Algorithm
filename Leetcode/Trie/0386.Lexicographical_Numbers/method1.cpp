#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        ans.reserve(n);
        for(int i = 1; i < 10; ++i) dfs(i, n);   
        return move(ans);
    }
    void dfs(int num, int n){
        if(num > n) return;
        ans.emplace_back(num);
        int k = num * 10 + 10;
        for(int i = num * 10; i < k; ++i){
            dfs(i, n);
        }
    }
};

int main(){
    Solution s;
    
    return 0;
}