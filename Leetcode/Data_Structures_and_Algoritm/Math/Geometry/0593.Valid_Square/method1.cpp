#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size());
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;
class solution {
public:
    bool validsquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto dist = [](auto& v1, auto& v2) {
            return pow(v1[0] - v2[0], 2) + pow(v1[1] - v2[1], 2);
        };
        if(dist(p1, p2) != dist(p2, p3)) {
            return false;
        }
        if(dist(p2, p3) != dist(p3, p4)) {
            return false;
        }
        if(dist(p3, p4) != dist(p4, p1)) {
            return false;
        }
        if(dist(p1, p3) == dist(p2, p4))
            return true;
        else
            return false;
    }
};
int main() {
    Solution s;

    return 0;
}