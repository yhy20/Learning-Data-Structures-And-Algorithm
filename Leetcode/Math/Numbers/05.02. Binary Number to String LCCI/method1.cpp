#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string printBin(double num) {
        int t = 0;
        double base = 0.5;
        string ans = "0.";
        while(num != 0 && t++ < 30) {
            if(num >= base) {
                ans += '1';
                num -= base;
            } else
                ans += '0';
            base /= 2;
        }
        if(t >= 30) return "ERROR";
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}