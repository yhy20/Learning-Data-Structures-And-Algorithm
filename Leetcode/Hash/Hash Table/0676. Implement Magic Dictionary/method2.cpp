#include <bits/stdc++.h>
using namespace std;

//模式匹配搜索
class MagicDictionary {
private:
    unordered_set<string> set;
    unordered_map<string, int> mp;

public:
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for(auto& s : dictionary) {
            set.insert(s);
            for(auto& c : s) {
                char letter = c;
                c = '*';
                ++mp[s];
                c = letter;
            }
        }
    }

    bool search(string searchWord) {
        bool isExist = (set.find(searchWord) != set.end());
        for(auto& c : searchWord) {
            char letter = c;
            c = '*';
            auto itr = mp.find(searchWord);
            c = letter;
            if(itr != mp.end() && (itr->second > 1 || (itr->second == 1 && !isExist))) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    MagicDictionary s;

    return 0;
}