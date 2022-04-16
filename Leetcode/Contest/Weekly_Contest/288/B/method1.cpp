#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minimizeResult(string& s) {
        int n1 = 0, n2 = s.size();
        while(s[n1] >= '0' && s[n1] <= '9') ++n1;
        int min = INT_MAX;
        string ans;
        for(int i = 0; i < n1; ++i) {
            for(int j = n1 + 2; j <= n2; ++j) {
                int num1 = (i == 0) ? 1 : stoi(s.substr(0, i));
                int num2 = stoi(s.substr(i, n1 - i)) + stoi(s.substr(n1 + 1, j - n1 - 1));
                int num3 = (j == n2) ? 1 : stoi(s.substr(j, n2 - j));
                int t = num1 * num2 * num3;
                if(t < min) {
                    min = t;
                    ans = s.substr(0, i) + "(" + s.substr(i, j - i) + ")" + s.substr(j, n2 - j);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}