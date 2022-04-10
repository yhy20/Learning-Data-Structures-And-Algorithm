#include <bits/stdc++.h>
using namespace std;

//暴力法匹配
class WordDictionary {
private:
    unordered_map<int, vector<string>> mp;

public:
    WordDictionary() {}

    void addWord(const string& word) {
        mp[word.size()].push_back(word);
    }

    bool search(const string& searchWord) {
        int n = searchWord.size();
        auto itr = mp.find(n);
        if(itr != mp.end()) {
            for(auto& word : itr->second) {
                bool ret = true;
                for(int i = 0; i < n; ++i) {
                    if(searchWord[i] == '.')
                        continue;
                    else if(searchWord[i] != word[i]) {
                        ret = false;
                        break;
                    }
                }
                if(ret) return true;
            }
        }
        return false;
    }
};

int main() {
    WordDictionary s;

    return 0;
}