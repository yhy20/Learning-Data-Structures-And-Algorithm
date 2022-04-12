#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> swapNumbers(vector<int>& n) {
        for(int i = 0; i < 32; ++i) {
            if(((n[0] & (1 << i)) ^ (n[1] & (1 << i))) != 0) {
                n[0] ^= (1 << i);
                n[1] ^= (1 << i);
            }
        }
        return move(n);
    }
};

int main() {
    Solution s;

    return 0;
}