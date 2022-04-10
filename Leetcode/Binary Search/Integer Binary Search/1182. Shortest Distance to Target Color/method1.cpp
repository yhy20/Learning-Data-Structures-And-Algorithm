#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> a[3];
        for(int i = 0; i < colors.size(); ++i) {
            a[colors[i] - 1].push_back(i);
        }
        vector<int> ans;
        ans.reserve(colors.size());
        for(auto& v : queries) {
            int i = v[0];
            int color = v[1] - 1;
            if(a[color].empty())
                ans.push_back(-1);
            else {
                auto itr = upper_bound(a[color].begin(), a[color].end(), i);
                if(itr == a[color].end())
                    ans.push_back(abs(*(--itr) - i));
                else if(itr == a[color].begin())
                    ans.push_back(abs(*itr - i));
                else
                    ans.push_back(min(abs(*(itr--) - i), abs(*itr - i)));
            }
        }
        return move(ans);
    }
};

int main() {
    Solution s;

    return 0;
}