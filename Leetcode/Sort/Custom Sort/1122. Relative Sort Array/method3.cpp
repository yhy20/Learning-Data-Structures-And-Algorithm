#include <bits/stdc++.h>
using namespace std;

//本题数据范围小，可以使用计数排序
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = *max_element(arr1.begin(), arr1.end()) + 1;
        vector<int> count(n);
        for(auto num : arr1) {
            count[num]++;
        }
        int k = 0;
        for(auto num : arr2) {
            int t = count[num];
            for(int i = 0; i < t; ++i) {
                arr1[k++] = num;
            }
            count[num] = 0;
        }
        for(int i = 0; i < n; ++i) {
            int t = count[i];
            for(int j = 0; j < t; ++j) {
                arr1[k++] = i;
            }
        }
        return move(arr1);
    }
};

int main() {
    Solution s;

    return 0;
}