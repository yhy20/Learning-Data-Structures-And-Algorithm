#include <bits/stdc++.h>
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

class Encrypter {
public:
    unordered_map<char, string> mp;
    unordered_map<string, int> cnt;
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        rep(i, 0, k.size()) mp[k[i]] = v[i];
        rep(i, 0, d.size()) {
            string str = encrypt(d[i]);
            if(str != "") ++cnt[str];
        }
    }

    string encrypt(string word1) {
        string res;
        for(auto c : word1) {
            if(mp.count(c)) {
                res += mp[c];
            } else
                return "";
        }
        return move(res);
    }

    int decrypt(string word2) {
        return cnt.count(word2) ? cnt[word2] : 0;
    }
};

int main() {
    Encrypter;

    return 0;
}