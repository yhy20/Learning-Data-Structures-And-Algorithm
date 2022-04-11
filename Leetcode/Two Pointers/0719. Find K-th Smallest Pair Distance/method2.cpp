#include <bits/stdc++.h>
using namespace std;

//枚举全部距离 + 优先级队列(TLE)
class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<int> q;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                q.push(nums[j] - nums[i]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};

int main() {
    Solution s;

    return 0;
}