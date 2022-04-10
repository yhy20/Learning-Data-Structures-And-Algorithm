#include <bits/stdc++.h>
using namespace std;

//转化为一维的topK问题来处理
//一维数组 + (sort or priority_queue or quicksort)
//此解法完全没有用到原矩阵的结构性质

//一维数组 + sort
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> a;
        a.reserve(n * n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                a.push_back(matrix[i][j]);
            }
        }
        sort(a.begin(), a.end());
        return a[k - 1];
    }
};

//一维数组 + priority_queue
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                q.push(matrix[i][j]);
                if(q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};

//一维数组 + quicksort
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> a;
        a.reserve(n * n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                a.push_back(matrix[i][j]);
            }
        }
        nth_element(a.begin(), a.begin() + k - 1, a.end());
        return a[k - 1];
    }
};

int main() {
    Solution s;

    return 0;
}