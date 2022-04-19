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
    string digitSum(string s, int k) {
        while(k<s.size()){
            string str;
            for(int i = 0; i <= s.size(); i+=k) {
                int t = 0;
                int n = min(i + k, int(s.size()));
                rep(j, i, n) {
                    t += s[j] - '0';
                }
                str += to_string(t);     
            }
            s = str;
        }
        return s;
    }
};

int main(){
    //Solution s;
    
    return 0;
}