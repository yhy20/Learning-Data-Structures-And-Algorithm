#include <bits/stdc++.h>
using namespace std;

class ArrayReader {
public:
    int get(int index) const;
};

//本题比较有意思，长度倍增 + 回溯
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        return dfs(reader, target, 0);
    }
    int dfs(const ArrayReader& reader, int target, int pre) {
        if(reader.get(pre) == INT_MAX) return -1;
        int curr = pre + 1;
        if(reader.get(curr) == INT_MAX) return (target == reader.get(pre)) ? pre : -1;
        while(reader.get(curr) != INT_MAX && target > reader.get(curr)) {
            pre = curr;
            curr = curr << 1;
        }
        if(reader.get(curr) != INT_MAX)
            return binarySearch(reader, pre, curr, target);

        return dfs(reader, target, pre + 1);
    }
    int binarySearch(const ArrayReader& reader, int left, int right, int target) {
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            int val = reader.get(mid);
            if(val == target)
                return mid;
            else if(val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}