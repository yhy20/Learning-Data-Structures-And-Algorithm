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

bool isPrime(int x) {
    int n = int(sqrt(x));
    for(int i = 2; i <= n; ++i) {
        if(x % i == 0) return false;
    }
    return true;
}

ll ans = 0;
int sum = 0;
int num = 0;

void dfs(vector<int> &a, int index, int k) {
    if(num == k && isPrime(sum)) {
        ++ans;
        return;
    }
    if(index == a.size()) return;

    sum += a[index];
    ++num;
    dfs(a, index + 1, k);
    sum -= a[index];
    --num;

    dfs(a, index + 1, k);
}

int main() {
    ios;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    dfs(a, 0, k);
    cout << ans << endl;
    return 0;
}