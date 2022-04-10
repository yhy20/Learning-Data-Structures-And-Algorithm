#include <bits/stdc++.h>
using namespace std;

//实数二分的第二种形式，mid +- 比所需精度更小的数，直到 l > r
class Solution {
public:
    bool check(vector<int>& a, double d, int k) {
        int used = 0;
        for(int i = 1; i < a.size(); ++i) {
            used += int((a[i] - a[i - 1]) / d);
        }
        return used <= k;
    }
    double minmaxGasDist(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        double l = 0, r = 0;
        for(int i = 1; i < a.size(); ++i) r = max(r, double(a[i] - a[i - 1]));
        double ans = 0;
        while(l < r) {
            double mid = (r + l) / 2.0;
            if(check(a, mid, k)) {
                ans = mid;
                r = mid - 1e-7;
            } else
                l = mid + 1e-7;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}
