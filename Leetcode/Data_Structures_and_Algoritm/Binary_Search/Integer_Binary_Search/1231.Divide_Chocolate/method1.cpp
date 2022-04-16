#include<bits/stdc++.h>
using namespace std;

//注意每一块都由一些连续的小块组成, 二分查找即可
class Solution {
public:
    bool check(vector<int>& a, int d, int k){
        int sum = 0, count = 0;
        for(auto num : a){
            sum += num;
            if(sum >= d){
                sum = 0;
                ++count;
            }
        }
        return count >= k;
    }
    int maximizeSweetness(vector<int>& a, int k) {
        int sum = 0;
        for(auto num : a) sum += num;
        ++k;
        int l = 1, r = sum, ans = 1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if(long(mid) * k > sum || !check(a, mid, k)){
                r = mid - 1;
            }else{
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    
    return 0;
}