#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()

const double PI = acos(-1.0);
const double eps = 1e-6;
const ll mod = 32768;
const int inf = 0x3f3f3f3f;

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main() {
    ios;
    int tt;
    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        int ans = 15;
        for(int i = 0; i <= 15; ++i) {
            for(int j = 0; j <= 15; ++j) {
                if((n + i) * (1 << j) % mod == 0) {
                    ans = min(ans, i + j);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}