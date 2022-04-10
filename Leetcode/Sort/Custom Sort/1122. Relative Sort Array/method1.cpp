#include <bits/stdc++.h>
using namespace std;

//自定义排序
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr2.size(); ++i) {
            mp[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int num1, int num2) -> bool {
            auto itr1 = mp.find(num1);
            auto itr2 = mp.find(num2);
            if(itr1 != mp.end() && itr2 != mp.end())
                return itr1->second < itr2->second;
            else if(itr1 != mp.end())
                return true;
            else if(itr2 != mp.end())
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