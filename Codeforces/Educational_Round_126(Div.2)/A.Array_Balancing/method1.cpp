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
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

const int N = 30;
int a[N], b[N];

int n;
int main() {
    ios;
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        long long ans = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]) > abs(a[i] - b[i + 1]) + abs(b[i] - a[i + 1]))
                swap(a[i + 1], b[i + 1]);
            ans += abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}