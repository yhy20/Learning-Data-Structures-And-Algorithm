#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quciksort(nums, 0, nums.size());
        return nums;
    }
    //前闭后开区间排序
    void quciksort(vector<int>& nums, int l, int r) {
        if(l + 1 >= r) return;
        int pos = l + rand() % (r - l);
        int pivot = nums[pos];
        swap(nums[pos], nums[r - 1]);
        int index = l;
        /*
        for(int j = l; j < r; ++j){
            if(nums[j] <= pivot)
                swap(nums[index++], nums[j]);
        }
        quciksort(nums, l, index - 1);
        quciksort(nums, index , r);
        */
        for(int j = l; j < r - 1; ++j) {
            if(nums[j] <= pivot)
                swap(nums[index++], nums[j]);
        }
        swap(nums[index], nums[r - 1]);
        quciksort(nums, l, index);
        quciksort(nums, index + 1, r);
    }
};

int main() {
    Solution s;

    return 0;
}
