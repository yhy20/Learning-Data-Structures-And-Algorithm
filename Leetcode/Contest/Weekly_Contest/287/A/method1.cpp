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
    int convertTime(string a, string b) {
        int t1 = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
        int t2 = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3, 2));
        int diff = (t2 - t1 + 24 * 60) % (24 * 60);
        int array[4] = {60, 15, 5, 1};
        int ans = 0;
        rep(i, 0, 4) {
            ans += diff / array[i];
            diff %= array[i];
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}