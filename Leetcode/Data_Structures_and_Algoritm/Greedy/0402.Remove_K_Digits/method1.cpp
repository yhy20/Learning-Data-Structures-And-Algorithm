#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(int i = 0; i < num.size(); ++i) {
            while(k > 0 && !s.empty() && s.back() > num[i] && k--) s.pop_back();
            if(!(s.empty() && num[i] == '0')) s.push_back(num[i]);
        }
        int end = (int)s.size() - k;
        return end > 0 ? s.substr(0, end) : "0";
    }
};

int main() {
    Solution s;

    return 0;
}

