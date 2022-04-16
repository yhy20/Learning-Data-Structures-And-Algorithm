#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFlowers(vector<vector<int>>& a) {
        vector<int> hash(a.size() + 1);
        int ans = 0;
        for(auto& v : a) {
            ans = max({ans, ++hash[v[0]], ++hash[v[1]]});
        }
        return ans + 1;
    }
};
int main() {
    Solution s;

    return 0;
}