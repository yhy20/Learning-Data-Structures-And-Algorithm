#include <bits/stdc++.h>
using namespace std;

// binarySearch + 字符串hash
class Solution {
public:
    typedef unsigned long long ull;
    static const int N = 1010, P = 13131;
    ull h1[N], p1[N], h2[N], p2[N];
    int n1, n2;
    ull get_hash(ull h[], ull p[], ull l, ull r) {
        return l == 0 ? h[r] : h[r] - h[l - 1] * p[r - l + 1];
    }
    bool check(int d) {
        unordered_set<ull> set;
        for(int i = 0; i + d <= n1; ++i) {
            set.insert(get_hash(h1, p1, i, i + d - 1));
        }
        for(int j = 0; j + d <= n2; ++j) {
            if(set.count(get_hash(h2, p2, j, j + d - 1))) return true;
        }
        return false;
    }
    void hash(vector<int>& v, ull h[], ull p[], int n) {
        h[0] = v[0] + 1;
        p[0] = 1;
        for(int i = 1; i < n; ++i) {
            h[i] = h[i - 1] * P + v[i] + 1;
            p[i] = p[i - 1] * P;
        }
    }
    int findLength(vector<int>& a, vector<int>& b) {
        n1 = a.size();
        n2 = b.size();
        hash(a, h1, p1, n1);
        hash(b, h2, p2, n2);
        int ans = 0;
        int l = 1, r = min(n1, n2);
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}