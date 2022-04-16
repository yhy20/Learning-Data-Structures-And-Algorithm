#include<bits/stdc++.h>
using namespace std;

//简单二分查找
class Solution {
public:
    bool check(vector<int>& a, int d, int days){
        int sum = 0;
        int need = 1;
        for(auto num : a){
            if(sum + num > d){
                ++need;
                sum = num;
            }else sum += num;
        }
        return need <= days;
    }
    int shipWithinDays(vector<int>& a, int days) {
        int sum = 0;
        for(auto num : a) sum += num;
        int l = *max_element(a.begin(), a.end());
        int r = sum;
        int ans = -1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if(check(a, mid, days)){
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        return ans;
    }
};

int main(){
    Solution s;
    
    return 0;
}