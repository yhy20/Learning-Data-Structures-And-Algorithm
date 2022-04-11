#include <bits/stdc++.h>
using namespace std;

//实数二分的第一种形式，r - l 小于精度eps

//我写的第一份代码，check函数没有仔细思考，TLE了
class Solution1 {
public:
    const double eps = 1e-6;
    bool check(vector<int>& a, double d, int k) {
        double pre = a[0] + d;
        for(int i = 1; i < a.size(); ++i) {
            if(pre < a[i]) {
                while(pre < a[i]) {
                    if(--k < 0) return false;
                    pre += d;
                }
                pre = a[i] + d;
            } else
                pre = a[i] + d;
        }
        return true;
    }
    double minmaxGasDist(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        double l = 0, r = 0;
        for(int i = 1; i < a.size(); ++i) r = max(r, double(a[i] - a[i - 1]));
        double ans = 0;
        while(r - l > eps) {
            double mid = (r + l) / 2.0;
            if(check(a, mid, k)) {
                ans = mid;
                r = mid;
            } else
                l = mid;
        }
        return ans;
    }
};

//优化check函数计算的版本
class Solution {
public:
    const double eps = 1e-6;
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
        while(r - l > eps) {
            double mid = (r + l) / 2.0;
            if(check(a, mid, k)) {
                ans = mid;
                r = mid;
            } else
                l = mid;
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}