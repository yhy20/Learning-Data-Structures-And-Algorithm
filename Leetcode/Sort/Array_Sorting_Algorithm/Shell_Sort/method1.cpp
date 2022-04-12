#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& nums) {
    int n = nums.size(), increment = n;
    do {
        increment = increment / 3 + 1;
        for(int i = increment; i < n; ++i) {
            if(nums[i] < nums[i - increment]) {
                int temp = nums[i], j = i - increment;
                while(j >= 0 && temp < nums[j]) {
                    nums[j + increment] = nums[j];
                    j -= increment;
                }
                nums[j + increment] = temp;
            }
        }
    } while(increment > 1);
}

int main() {
    return 0;
}