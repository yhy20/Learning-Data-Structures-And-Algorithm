#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, i = 0;
        while(i < n) {
            sum += gas[i] - cost[i];
            if(sum < 0) {
                sum = 0;
                ++i;
                continue;
            }
            bool flag = true;
            for(int j = i + 1; j % n != i; ++j) {
                sum += gas[j % n] - cost[j % n];
                if(sum < 0) {
                    if(j >= n) return -1;
                    i = j;
                    sum = 0;
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}