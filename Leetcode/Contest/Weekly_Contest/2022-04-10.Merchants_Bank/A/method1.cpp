#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string deleteText(string s, int k) {
        if(s[k] == ' ') return move(s);
        int n = s.size();
        int l = k, r = k;
        while(l >= 0 && s[l] != ' ') --l;
        while(r < n && s[r] != ' ') ++r;
        while(l >= 0 && s[l] == ' ') --l;
        while(r < n && s[r] == ' ') ++r;
        if(l < 0 && r >= n)
            return "";
        else if(r >= n)
            return s.substr(0, l + 1);
        else if(l < 0)
            return s.substr(r, n - r + 1);
        else
            return s.substr(0, l + 1) + " " + s.substr(r, n - r + 1);
    }
};

int main() {
    Solution s;

    return 0;
}