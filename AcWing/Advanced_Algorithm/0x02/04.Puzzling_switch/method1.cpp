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

int ans;
vector<string> a(5), b(5);
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int dirs3[3][2] = {{0, 1}, {1, 0}, {0, -1}};
int solve() {
    int ret = 10;
    for(int i = 0; i < 32; ++i) {
        int k = 0;
        b = a;
        k += __builtin_popcount(i);
        for(int j = 0; j < 5; ++j) {
            if((i >> j) & 1) {
                b[0][j] = b[0][j] == '1' ? '0' : '1';
                for(int h = 0; h < 4; ++h) {
                    int nx = 0 + dirs[h][0];
                    int ny = j + dirs[h][1];
                    if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                        b[nx][ny] = b[nx][ny] == '1' ? '0' : '1';
                    }
                }
            }
        }
        for(int m = 1; m < 5; ++m) {
            for(int j = 0; j < 5; ++j) {
                if(b[m - 1][j] == '0') {
                    if(++k > 6) break;
                    b[m][j] = b[m][j] == '1' ? '0' : '1';
                    for(int h = 0; h < 3; ++h) {
                        int nx = m + dirs3[h][0];
                        int ny = j + dirs3[h][1];
                        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                            b[nx][ny] = b[nx][ny] == '1' ? '0' : '1';
                        }
                    }
                }
            }
            if(k > 6) break;
        }
        if(k > 6) continue;
        bool flag = true;
        for(int j = 0; j < 5; ++j) {
            if(b[4][j] != '1') {
                flag = false;
                break;
            }
        }
        if(flag) ret = min(ret, k);
    }
    return ret <= 6 ? ret : -1;
}

int main() {
    ios;
    int tt;
    cin >> tt;
    while(tt--) {
        for(int i = 0; i < 5; ++i) {
            cin >> a[i];
        }
        ans = solve();
        cout << ans << '\n';
    }
    return 0;
}