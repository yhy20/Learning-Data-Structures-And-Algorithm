#include <bits/stdc++.h>
using namespace std;

#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

//本题踩了unordered_map的大坑，cf上特殊的cases会导致unordered_map
//产生大量的hash冲突，最后TLE
// https://codeforces.com/blog/entry/62393
int main() {
    ios;
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        //使用unordered_map代替map会超时
        // unordered_map<int, int> cnt;
        map<int, int> cnt;
        int a, mx = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a;
            mx = max(mx, ++cnt[a]);
        }
        int ans = n - mx;
        while(mx < n) {
            ++ans;
            mx = mx * 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
