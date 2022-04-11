#include <bits/stdc++.h>
using namespace std;

//自定义排序优化
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> mp(1005);
        for(int i = 0; i < arr2.size(); ++i) {
            mp[arr2[i]] = i + 1;
        }
        sort(arr1.begin(), arr1.end(), [&](int num1, int num2) -> bool {
            auto key1 = mp[num1];
            auto key2 = mp[num2];
            if(key1 && key2)
                return key1 < key2;
            else if(key1)
                return true;
            else if(key2)
                return false;
            else
                return num1 < num2;
        });
        return move(arr1);
    }
};

int main() {
    Solution s;

    return 0;
}