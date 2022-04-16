#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int get(string& s) {
        int ret = 0;
        for(auto c : s) {
            ret |= 1 << (c - 'a');
        }
        return ret;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = get(words[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if((a[i] & a[j]) == 0) {
                    ans = max(ans, int(words[i].length() * words[j].length()));
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