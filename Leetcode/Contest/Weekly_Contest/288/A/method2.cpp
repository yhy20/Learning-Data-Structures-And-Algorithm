#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        vector<int> a, b;
        vector<bool> c;
        while(num) {
            int t = num % 10;
            if(t & 1) {
                a.push_back(t);
                c.push_back(true);
            } else {
                b.push_back(t);
                c.push_back(false);
            }
            num /= 10;
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        reverse(c.begin(), c.end());
        int t1 = 0, t2 = 0, ans = 0;
        for(auto flag : c) {
            if(flag)
                ans = ans * 10 + a[t1++];
            else
                ans = ans * 10 + b[t2++];
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}