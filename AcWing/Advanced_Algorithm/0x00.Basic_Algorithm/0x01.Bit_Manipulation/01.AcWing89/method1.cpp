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

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int a, b, p;
ll myPow(ll a, ll b) {
    if(b == 0) return 1 % p;
    ll y = myPow(a, b >> 1);
    return b & 1 ? ((y * y % p) * a) % p : y * y % p;
}

//递归快速幂
int main() {
    ios;
    cin >> a >> b >> p;
    cout << myPow(a % p, b) << '\n';
    return 0;
}