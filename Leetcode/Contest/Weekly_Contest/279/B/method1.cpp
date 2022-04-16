#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size());
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;

class Solution {
public:
    long long smallestNumber(long long num) {
        bool flag = num > 0 ? true : false;
        num = abs(num);
        string s = to_string(num);
        if(flag) {
            sort(all(s));
            rep(i, 0, s.size()) {
                if(s[i] != '0') {
                    swap(s[i], s[0]);
                    break;
                }
            }
            return stol(s);
        } else {
            sort(rall(s));
            return -stol(s);
        }
    }
};

int main() {
    Solution s;

    return 0;
}