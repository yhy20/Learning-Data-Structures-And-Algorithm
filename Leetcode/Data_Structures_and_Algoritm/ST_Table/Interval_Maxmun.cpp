#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5e5 + 10;

int dp[N][16];

int main() {
    ios;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> dp[i][0];
    int k = 1, p = log2(n);
    while (k <= p) {
        int d = 1 << k;
        for (int i = 0; i + d <= n; ++i) {
            dp[i][k] = max(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
        }
        ++k;
    }
    int L, R;
    while (q--) {
        cin >> L >> R;
        --L;
        --R;
        int k = log2(R - L + 1);
        cout << max(dp[L][k], dp[R - (1 << k) + 1][k]) << endl;
    }
    return 0;
}
