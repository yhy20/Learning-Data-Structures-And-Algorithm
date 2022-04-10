#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for(int i = n - 1; i >= 1; --i) {
        bool flag = true;
        for(int j = 0; j < i; ++j) {
            if(nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = false;
            }
        }
        if(flag) break;
    }
}

int main() {
    return 0;
}