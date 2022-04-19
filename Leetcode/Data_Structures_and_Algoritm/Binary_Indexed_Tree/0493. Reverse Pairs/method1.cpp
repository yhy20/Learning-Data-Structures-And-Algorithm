#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size());
#define rall(x) x.rbegin(), x.rend()
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
    int reversePairs(vector<int>& a) {
        set<ll> set;
        for(auto num : a) {
            set.insert(num);
            set.insert(ll(num) * 2);
        }
        unordered_map<long long, int> map;
        int idx = 1;
        for(auto num : set) {
            map[num] = idx++;
        }
        BIT<int> bit(map.size());
        int ans = 0;
        for(auto num : a) {
            ans += bit.sum(map[ll(num) * 2] + 1, idx - 1);
            bit.add(map[num], 1);
        }
        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}