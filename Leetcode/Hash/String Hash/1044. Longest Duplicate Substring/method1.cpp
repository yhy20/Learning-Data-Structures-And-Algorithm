#include <bits/stdc++.h>
using namespace std;

//字符串hash将unordered_set各种操作的时间复杂度降到O(1)
class Solution {
public:
    typedef unsigned long long ull;
    static const int N = 3e4 + 10, P = 13131;
    ull h[N], p[N];
    ull get_hash(ull l, ull r) {
        return l == 0 ? h[r] : h[r] - h[l - 1] * p[r - l + 1];
    }
    int check(string& s, int d) {
        unordered_set<ull> set;
        int n = s.length();
        for(int i = 0; i + d <= n; ++i) {
            ull hash = get_hash(i, i + d - 1);
            if(set.count(hash)) return i;
            set.insert(hash);
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        int n = s.length();
        h[0] = s[0] - 'a' + 1;
        p[0] = 1;
        for(int i = 1; i < n; ++i) {
            h[i] = h[i - 1] * P + s[i] - 'a' + 1;
            p[i] = p[i - 1] * P;
        }
        int l = 1, r = n;
        int ans = -1, len = -1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            int t = check(s, mid);
            if(t >= 0) {
                ans = t;
                len = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans == -1 ? "" : move(s.substr(ans, len));
    }
};

int main() {
    Solution s;

    return 0;
}