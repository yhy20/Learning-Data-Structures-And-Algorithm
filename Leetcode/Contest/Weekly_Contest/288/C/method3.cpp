#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
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
    int maximumProduct(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto num : a) q.push(num);
        while(k-- > 0) {
            int t = q.top() + 1;
            q.pop();
            q.push(t);
        }
        ll ans = 1;
        while(!q.empty()) {
            ans = ans * q.top() % mod;
            q.pop();
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}