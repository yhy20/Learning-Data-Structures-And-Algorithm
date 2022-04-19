#include<bits/stdc++.h>
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

class Solution {
public:
    int minimumRounds(vector<int>& a) {
        unordered_map<int, int> mp;
        for(auto num : a) ++mp[num];
        int ans = 0;
        for(auto& [key, val] : mp) {
            if(val==1)return -1;
            if(val%3==1){
                ans+=val/3-1+2;
            }else if(val%3==2){
                ans+=val/3+1;
            }else ans+=val/3;
        }
        return ans;
    }
};

int main(){
    //Solution s;
    
    return 0;
}