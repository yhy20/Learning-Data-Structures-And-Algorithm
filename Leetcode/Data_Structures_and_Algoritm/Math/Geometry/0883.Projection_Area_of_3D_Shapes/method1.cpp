#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size());
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;
const int inf = 1000;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        unordered_map<int, int> mp1, mp2, mp3;
        int n = grid[0].size(), m = grid[1].size();
        int ans = 0;
        rep(i, 0, n) {
            rep(j,0,m){
                int t1 =  i* inf + j;
                int t2 = i* inf + grid[i][j];
                int t3 = j *inf + grid[i][j];
                if(!mp1.count(t1)){
                    ++ans;
                    mp1[t1]++;
                }
                if(!mp2.count(t2)){
                    ++ans;
                    mp2[t2]++;
                }
                if(!mp3.count(t3)){
                    ++ans;
                    mp3[t3]++;
                }
            }
        }
    }
};


int main(){
    Solution s;
    
    return 0;
}