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

int n, m;
vector<int> temp;
void dfs(int i) {
    if(temp.size() > m || temp.size() + n - i + 1 < m) return;
    if(temp.size() == m) {
        for(int j = 0; j < m; ++j) {
            cout << temp[j];
            if(j < m - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }

    temp.pb(i);
    dfs(i + 1);
    temp.pop_back();

    dfs(i + 1);
}

int main() {
    ios;
    cin >> n >> m;
    dfs(1);
    return 0;
}