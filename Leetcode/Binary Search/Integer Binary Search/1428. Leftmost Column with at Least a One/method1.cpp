#include <bits/stdc++.h>
using namespace std;

class BinaryMatrix {
public:
    int get(int row, int col);
    vector<int> dimensions();
};

//简单的矩阵二分查找
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& b) {
        int ans = -1;
        int m = b.dimensions()[0], n = b.dimensions()[1];
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            bool flag = false;
            for(int i = 0; i < m; ++i) {
                if(b.get(i, mid)) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}