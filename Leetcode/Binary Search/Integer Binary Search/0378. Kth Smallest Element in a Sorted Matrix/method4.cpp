#include <bits/stdc++.h>
using namespace std;

//归并排序
//此归并排序在空间上可以优化
class Solution {
public:
    vector<int> merge(vector<vector<int>>& a, int l, int r) {
        if(l == r) return move(a[l]);
        int mid = l + ((r - l) >> 1);
        auto a1 = merge(a, l, mid);
        auto a2 = merge(a, mid + 1, r);
        int n1 = a1.size(), n2 = a2.size();
        vector<int> ret(n1 + n2);
        int t1 = 0, t2 = 0, k = 0;
        while(t1 < n1 && t2 < n2) {
            if(a1[t1] <= a2[t2])
                ret[k++] = a1[t1++];
            else
                ret[k++] = a2[t2++];
        }
        while(t1 < n1) ret[k++] = a1[t1++];
        while(t2 < n2) ret[k++] = a2[t2++];
        return move(ret);
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto array = merge(matrix, 0, matrix.size() - 1);
        return array[k - 1];
    }
};

int main() {
    Solution s;

    return 0;
}