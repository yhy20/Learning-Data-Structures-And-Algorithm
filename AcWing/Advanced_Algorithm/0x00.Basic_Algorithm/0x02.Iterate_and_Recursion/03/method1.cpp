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

const int N = 12;
int n;
vector<int> temp;
bool seen[N];
void dfs() {
    if(temp.size() == n) {
        for(int j = 0; j < n; ++j) {
            cout << temp[j];
            if(j < n - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(!seen[i]) {
            seen[i] = true;
            temp.pb(i);
            dfs();
            temp.pop_back();
            seen[i] = false;
        }
    }
}
int main() {
    ios;
    cin >> n;
    memset(seen, 0, sizeof(seen));
    dfs();
    return 0;
}