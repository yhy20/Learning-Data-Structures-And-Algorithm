#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
    void adjust(vector<int>& nums, int i, int len) {
        while((i << 1) + 1 <= len) {
            int lson = (i << 1) + 1;
            int rson = (i << 1) + 2;
            int large = 0;
            if(nums[i] < nums[lson]) {
                large = lson;
            } else {
                large = i;
            }

            if(rson <= len && nums[large] < nums[rson])
                large = rson;

            if(large != i) {
                swap(nums[i], nums[large]);
                i = large;
            } else {
                break;
            }
        }
    }
    void heapSort(vector<int>& nums) {
        if(nums.size() < 2) return;
        int len = nums.size() - 1;
        for(int i = len / 2; i >= 0; --i)
            adjust(nums, i, len);
        for(int i = len; i >= 1; --i) {
            swap(nums[i], nums[0]);
            adjust(nums, 0, i - 1);
        }
    }
};

int main() {
    Solution s;

    return 0;
}