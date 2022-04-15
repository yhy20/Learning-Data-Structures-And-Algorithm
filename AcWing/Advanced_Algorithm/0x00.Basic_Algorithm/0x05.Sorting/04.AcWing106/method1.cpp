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
    int tt;
    cin >> tt;
    while(tt--) {
        int num, n;
        cin >> num >> n;
        cout << num << ' ' << (n + 1) / 2 << "\n";
        int x;
        priority_queue<int> maxHeap;
        maxHeap.push(INT_MIN);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(INT_MAX);
        int cnt = 0;
        rep(i, 0, n) {
            cin >> x;
            if(x < maxHeap.top()) {
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }
            if(maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if(minHeap.size() - maxHeap.size() >= 2) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if((i & 1) == 0) {
                cout << minHeap.top() << ' ';
                if(++cnt == 10 && i != n - 1) {
                    cout << "\n";
                    cnt = 0;
                }
            }
        }
        cout << endl;
    }
    return 0;
}