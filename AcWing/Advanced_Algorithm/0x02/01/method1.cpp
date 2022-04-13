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

const int N = 17;
int n, temp[N];
void dfs(int i) {
    if(i == n + 1) {
        for(int j = 1; j <= n; ++j) {
            if(temp[j]) {
                cout << temp[j];
                if(j < n) cout << ' ';
            }
        }
        cout << '\n';
        return;
    }
    dfs(i + 1);

    temp[i] = i;
    dfs(i + 1);
    temp[i] = 0;
}

int main() {
    ios;
    cin >> n;
    dfs(1);
    return 0;
}