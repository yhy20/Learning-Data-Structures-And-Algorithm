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

//一个模拟题
class ATM {
public:
    vector<ll> a, b = {20, 50, 100, 200, 500};
    ATM() : a(5) {
    }
    void deposit(vector<int> banknotesCount) {
        rep(i, 0, 5) a[i] += banknotesCount[i];
    }

    vector<int> withdraw(ll amount) {
        VI ans(5);
        ll t = amount;
        per(i, 0, 5) {
            if(t < b[i] || a[i] == 0) continue;
            ll m = t / b[i];
            t -= min(m, a[i]) * b[i];
        }
        if(t > 0) return {-1};
        per(i, 0, 5) {
            if(amount < b[i] || a[i] == 0) continue;
            int m = min(amount / b[i], a[i]);
            ans[i] = m;
            a[i] -= m;
            amount -= m * b[i];
        }
        return ans;
    }
};

int main() {
    ATM;

    return 0;
}