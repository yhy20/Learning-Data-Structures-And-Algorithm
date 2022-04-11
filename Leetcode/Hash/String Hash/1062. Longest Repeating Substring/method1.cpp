#include <bits/stdc++.h>
using namespace std;

// binarySearch + unordered_set
class Solution {
public:
    bool check(string& s, int d) {
        unordered_set<string> set;
        int n = s.length();
        for(int i = 0; i <= n - d; ++i) {
            string str = s.substr(i, d);
            if(set.count(str))
                return true;
            else
                set.insert(move(str));
        }
        return false;
    }
    int longestRepeatingSubstring(string s) {
        int l = 1, r = s.size() - 1, ans = 0;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(check(s, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}