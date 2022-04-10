#include <bits/stdc++.h>
using namespace std;

void insertSort(vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        int temp = nums[i], j = i - 1;
        while(j >= 0 && nums[j] > temp) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = temp;
    }
}

int main() {
    return 0;
}