#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size());
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main() {
    ios;
    int n;
    cin>>n;
    vector<PII>a(n);
    VI ans(n);
    vector<bool>seen(n);
    rep(i,0,n)cin>>a[i].fi>>a[i].se;
    sort(all(a));
    int num=1;
    while(true){
        int r=-1;
        rep(i,0,n){
            if(!seen[i]&&(r<a[i].fi)){
                seen[i]=true;
                ans[i]=num;
                r=a[i].se;
            }
        }
        if(r==-1)break;
        ++num;
    }
    cout<<num-1<<'\n';
    rep(i,0,n)cout<<ans[i]<<'\n';
    return 0;
}