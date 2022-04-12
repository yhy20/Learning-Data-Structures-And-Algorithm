#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> temp;
    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    //前闭后闭区间归并排序
    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int mid = l + ((r - l) >> 1);
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int t1 = l, t2 = mid + 1, k = 0;
        while(t1 <= mid && t2 <= r) {
            if(nums[t1] <= nums[t2]) {
                temp[k++] = nums[t1++];
            } else {
                temp[k++] = nums[t2++];
            }
        }
        if(t1 <= mid) {
            while(mid >= t1) {
                nums[r--] = nums[mid--];
            }
        }
        for(int i = 0; i < k; ++i) {
            nums[l + i] = temp[i];
        }
    }
};

int main() {
    Solution s;

    return 0;
}