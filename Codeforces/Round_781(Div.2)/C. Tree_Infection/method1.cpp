#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int ans;

void dfs(vi& a) {
    if(a.empty()) return;
    int last = 0, n = a.size();
    for(int i = 1; i < n; ++i) {
        if(a[i] == a[0])
            last = i;
        else
            break;
    }
    --a[last];
    ++ans;
    for(int i = 0; i < n; ++i) --a[i];
    while(!a.empty() && a.back() <= 0) a.pop_back();
    dfs(a);
}

int main() {
    ios;
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vi a(n);
        ans = 0;
        for(int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            ++a[--x];
        }
        a.push_back(1);
        sort(a.rbegin(), a.rend());
        while(!a.empty() && a.back() == 0) a.pop_back();
        n = a.size();
        for(int i = 0; i < n; ++i) {
            ++ans;
            a[i] -= n - i;
        }
        sort(a.rbegin(), a.rend());
        while(!a.empty() && a.back() <= 0) a.pop_back();
        dfs(a);
        cout << ans << '\n';
    }
    return 0;
}