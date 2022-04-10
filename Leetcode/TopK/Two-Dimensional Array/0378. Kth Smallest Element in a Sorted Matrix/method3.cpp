#include <bits/stdc++.h>
using namespace std;

// binary search
class Solution {
public:
    bool check(vector<vector<int>>& a, int d, int k) {
        int count = 0, n = a.size();
        int row = 0, col = n - 1;
        while(row < n && col >= 0) {
            while(col >= 0 && a[row][col] > d) --col;
            count += col + 1;
            ++row;
        }
        return count >= k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1], ans = 0;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(check(matrix, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}