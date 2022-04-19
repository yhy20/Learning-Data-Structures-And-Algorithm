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

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // x+x+1+x+2=num,3x=num-3,x=num/3-1;
        if(num % 3 != 0) return {};
        ll x = num / 3 - 1;
        return {x, x + 1, x + 2};
    }
};

int main() {
    return 0;
}