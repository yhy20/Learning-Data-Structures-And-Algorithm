#include <bits/stdc++.h>
using namespace std;

//暴力法：逐一比较汉明距离
class MagicDictionary {
private:
    unordered_map<int, vector<string>> mp;

public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for(auto& s : dictionary) {
            mp[s.size()].push_back(move(s));
        }
    }

    bool search(const string& searchWord) {
        int n = searchWord.size();
        auto itr = mp.find(n);
        if(itr != mp.end()) {
            for(auto& word : itr->second) {
                int mismatch = 0;
                for(int i = 0; i < n; ++i) {
                    if(word[i] != searchWord[i]) {
                        if(++mismatch > 1) break;
                    }
                }
                if(mismatch == 1) return true;
            }
        }
        return false;
    }
};

int main() {
    MagicDictionary s;

    return 0;
}