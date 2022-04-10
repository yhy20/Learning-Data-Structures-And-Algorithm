#include <bits/stdc++.h>
using namespace std;

void selectSort(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n - 1; ++i) {
        int pos = i;
        for(int j = i + 1; j < n; ++j) {
            if(nums[j] < nums[pos]) {
                pos = j;
            }
        }
        swap(nums[i], nums[pos]);
    }
}

int main() {
    return 0;
}