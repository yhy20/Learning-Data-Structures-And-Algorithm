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

int ans = 15;
int n;

void dfs(int t) {
    if(t == 15) return;

}


int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        dfs(0);
        cout << ans << "\n";
    }
}