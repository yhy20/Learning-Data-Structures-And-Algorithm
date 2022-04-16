#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.size(); ++i) {
            int flag = (s[i] - '0') & 1;
            for(int j = i + 1; j < s.size(); ++j) {
                if(((s[j] - '0') & 1) == flag && s[j] > s[i]) {
                    swap(s[i], s[j]);
                }
            }
        }
        return stoi(s);
    }
};

int main() {
    Solution s;

    return 0;
}