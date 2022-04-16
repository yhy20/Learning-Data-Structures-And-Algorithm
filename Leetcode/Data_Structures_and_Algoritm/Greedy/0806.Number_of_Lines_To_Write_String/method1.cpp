#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row = 1, sum = 0;
        for(auto c : s) {
            sum += widths[c - 'a'];
            if(sum > 100) {
                ++row;
                sum = widths[c - 'a'];
            }
        }
        return {row, sum};
    }
};

int main() {
    Solution s;

    return 0;
}