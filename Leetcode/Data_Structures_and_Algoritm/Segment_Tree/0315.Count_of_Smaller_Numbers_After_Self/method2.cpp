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

template <typename T>
class BIT {
private:
    int n;
    vector<T> c;
    static int lowbit(int x) { return x & -x; }

public:
    BIT(int n) : n(n), c(n + 1) {}
    void add(int x, T v) {
        for(int i = x; i <= n; i += lowbit(i)) c[i] += v;
    }
    void add(int l, int r, T v) {
        add(l, v);
        add(r + 1, -v);
    }
    T sum(int x) {
        T ret = 0;
        for(int i = x; i >= 1; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
    int kth(T v) {
        int ret = 0;
        for(int i = 1 << 20; i >= 1; i >>= 1)
            if(ret + i < n && c[ret + i] < v) {
                ret += i;
                v -= c[ret];
            }
        return ret + 1;
    }
};

class Solution {
public:
    VI b;
    int query(int x) {
        return lower_bound(all(b), x) - b.begin();
    }
    vector<int> countSmaller(vector<int>& a) {
        b = a;
        sort(all(b));
        b.erase(unique(all(b)), b.end());
        VI ans(a.size());
        BIT<int> bit(b.size());
        per(i, 0, a.size()) {
            int index = query(a[i]);
            ans[i] = bit.sum(index);
            bit.add(index + 1, 1);
        }
        return move(ans);
    }
};

int main() {
    Solution s;

    return 0;
}