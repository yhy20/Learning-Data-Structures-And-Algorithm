#include<bits/stdc++.h>
using namespace std;

//sort
class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

//priority_queue
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> maxHeap;
        int n = arr.size();
        for(int i = 0; i < k; ++i){
            maxHeap.push(arr[i]);
        }
        for(int i = k; i < n; ++i){
            maxHeap.push(arr[i]);
            maxHeap.pop();
        }
        vector<int> ans(k--);
        while(!maxHeap.empty()){
            ans[k--] = maxHeap.top();
            maxHeap.pop();
        }
        return move(ans);
    }
};

int main(){
    Solution s;
    
    return 0;
}