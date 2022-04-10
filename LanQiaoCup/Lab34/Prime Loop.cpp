#include <bits/stdc++.h>
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

const double PI = acos(-1.0);
const double eps = 1e-6;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

bool isPrime(int n) {
    if(n <= 1) return false;
    int m = int(sqrt(n));
    for(int i = 2; i <= m; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

bool used[20] = {false};
bool dfs(vi &a, int n) {
    if(a.size() == n) {
        if(isPrime(a.front() + a.back())) {
            for(int i = 0; i < n; ++i) {
                cout << a[i];
                if(i < n - 1) cout << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    bool ret = false;
    for(int i = 2; i <= n; ++i) {
        if(!used[i]) {
            if(isPrime(a.back() + i)) {
                a.emplace_back(i);
                used[i] = true;
                ret |= dfs(a, n);
                used[i] = false;
                a.pop_back();
            }
        }
    }
    return ret;
}

int main() {
    ios;
    int n;
    cin >> n;
    vi temp;
    temp.push_back(1);
    memset(used, 0, sizeof(used));
    used[0] = true;
    used[1] = true;
    if(n & 1)
        cout << "No Answer" << endl;
    else {
        if(!dfs(temp, n)) cout << "No Answer" << endl;
    }
    return 0;
}