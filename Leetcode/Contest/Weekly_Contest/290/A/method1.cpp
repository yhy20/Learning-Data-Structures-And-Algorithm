#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for(auto& v:nums){
            for(auto num : v){
                mp[num]++;
            }
        }
        vector<int> ans;
        for(auto [key, val] : mp) {
            if(val == n){
                ans.pb(key);
            }
        }
        return move(ans);
    }
};

int main(){
    //Solution s;
    
    return 0;
}