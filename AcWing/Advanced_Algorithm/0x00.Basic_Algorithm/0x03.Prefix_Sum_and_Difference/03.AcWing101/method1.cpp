#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
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
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

map<PII, bool> existed;
int n, p, h, m;
int d[5005];
int main() {
    ios;
    cin >> n >> p >> h >> m;
    rep(i, 1, m + 1) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(existed[{a, b}]) continue;
        d[a + 1]--, d[b]++;
        existed[{a, b}] = true;
    }
    rep(i, 1, n + 1) {
        d[i] += d[i - 1];
        cout << d[i] + h << '\n';
    }
    return 0;
}