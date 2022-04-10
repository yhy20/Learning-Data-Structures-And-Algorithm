#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quciksort(nums, 0, nums.size() - 1);
        return nums;
    }
    //前闭后闭区间排序
    void quciksort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int pos = l + rand() % (r - l + 1);
        int pivot = nums[pos];
        swap(nums[pos], nums[r]);
        int index = l;
        /*
        for(int j = l; j <= r; ++j){
            if(nums[j] <= pivot)
                swap(nums[index++], nums[j]);
        }
        quciksort(nums, l, index - 2);
        quciksort(nums, index , r);
        */
        for(int j = l; j <= r - 1; ++j) {
            if(nums[j] <= pivot)
                swap(nums[index++], nums[j]);
        }
        swap(nums[index], nums[r]);
        quciksort(nums, l, index - 1);
        quciksort(nums, index + 1, r);
    }
};

int main() {
    Solution s;

    return 0;
}